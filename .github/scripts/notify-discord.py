#!/usr/bin/env python3
import json
import os
import sys
import requests
from datetime import datetime

def send_discord_notification(webhook_url, status, title, os_name, compiler, artifact_name=None):
    """
    Envoie une notification Discord riche avec les résultats du build
    """
    
    # Déterminer la couleur et l'emoji basé sur le statut
    if status == "success":
        color = 0x00FF00  # Vert
        status_text = "SUCCESS"
    elif status == "failure":
        color = 0xFF0000  # Rouge
        status_text = "FAILED"
    else:
        color = 0xFFFF00  # Orange
        status_text = "UNKNOWN"
    
    # Construire l'URL des logs
    repo = os.getenv("GITHUB_REPOSITORY", "Unknown")
    run_id = os.getenv("GITHUB_RUN_ID", "")
    run_number = os.getenv("GITHUB_RUN_NUMBER", "")
    branch = os.getenv("GITHUB_REF_NAME", "Unknown")
    commit_sha = os.getenv("GITHUB_SHA", "")[:7]
    actor = os.getenv("GITHUB_ACTOR", "Unknown")
    
    logs_url = f"https://github.com/{repo}/actions/runs/{run_id}" if run_id else "N/A"
    
    # Construire l'embed Discord
    embed = {
        "title": title,
        "description": f"Build #{run_number} - {status_text}",
        "color": color,
        "fields": [
            {
                "name": "Branche",
                "value": branch,
                "inline": True
            },
            {
                "name": "Commit",
                "value": commit_sha,
                "inline": True
            },
            {
                "name": "OS",
                "value": os_name,
                "inline": True
            },
            {
                "name": "Compilateur",
                "value": compiler,
                "inline": True
            },
            {
                "name": "Acteur",
                "value": actor,
                "inline": True
            },
            {
                "name": "Statut",
                "value": status_text,
                "inline": True
            }
        ],
        "timestamp": datetime.utcnow().isoformat() + "Z",
        "footer": {
            "text": "GitHub Actions",
            "icon_url": "https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png"
        }
    }
    
    # Ajouter les liens
    buttons = []
    
    if logs_url != "N/A":
        buttons.append({
            "type": 1,
            "components": [
                {
                    "type": 2,
                    "label": "View Logs",
                    "style": 5,
                    "url": logs_url
                }
            ]
        })
    
    # Construire le payload
    payload = {
        "username": "GitHub Actions",
        "avatar_url": "https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png",
        "embeds": [embed]
    }
    
    # Ajouter les components (boutons) si suppoertés
    if buttons:
        payload["components"] = buttons
    
    # Envoyer la notification
    try:
        response = requests.post(webhook_url, json=payload, timeout=10)
        response.raise_for_status()
        print("Discord notification sent successfully!")
        return True
    except requests.exceptions.RequestException as e:
        print(f"Failed to send Discord notification: {e}", file=sys.stderr)
        return False

if __name__ == "__main__":
    webhook_url = os.getenv("DISCORD_WEBHOOK")
    status = os.getenv("JOB_STATUS", "unknown")
    title = os.getenv("BUILD_TITLE", "Build Notification")
    os_name = os.getenv("RUNNER_OS", "Unknown")
    compiler = os.getenv("COMPILER", "Unknown")
    artifact_name = os.getenv("ARTIFACT_NAME")
    
    if not webhook_url:
        print("Error: DISCORD_WEBHOOK environment variable not set", file=sys.stderr)
        sys.exit(1)
    
    success = send_discord_notification(webhook_url, status, title, os_name, compiler, artifact_name)
    sys.exit(0 if success else 1)
