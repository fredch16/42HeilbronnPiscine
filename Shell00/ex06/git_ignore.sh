repo_root=$(git rev-parse --show-toplevel 2>/dev/null)

cd "$repo_root" || exit

git ls-files --ignored --exclude-standard --others
