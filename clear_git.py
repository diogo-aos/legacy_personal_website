from pathlib import Path
import shutil

def clear_git(target_dir: Path):
    for gd in target_dir.rglob(".git"):
        print(f"removing {gd}...")
        if gd.is_dir():
            shutil.rmtree(gd)
        else:
            gd.unlink()

clear_git(Path("content"))