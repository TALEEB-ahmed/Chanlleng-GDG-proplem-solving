
#!/bin/bash
set -e

echo "=== Connect project to GitHub ==="

if ! git --version >/dev/null 2>&1; then
    echo "Git is not installed."
    exit 1
fi

if [ ! -d ".git" ]; then
    git init
else
    echo "Git is already initialized."
fi

git add .

read -r -p "Enter commit message: " commit_message
commit_message=${commit_message:-"Initial commit"}

git commit -m "$commit_message"

read -r -p "Enter GitHub repository HTTPS URL: " repo_url

if git remote get-url origin >/dev/null 2>&1; then
    echo "Remote 'origin' already exists:"
    git remote get-url origin
    echo "Remove or update it manually before running this script again."
    exit 1
fi

git remote add origin "$repo_url"

git branch -M main

git push -u origin main

echo "Project successfully connected to GitHub!"
