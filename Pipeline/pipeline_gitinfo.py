import os

from git import Commit, Repo
from repopath import repopath

with Repo(repopath) as repo:
    assert not repo.bare

    string = f"{repo.active_branch.name}-{repo.commit().hexsha[:7]}"

    with open(f"{repopath}/Content/GITINFO", "w") as f:
        f.write(string)
        print(f"Pipeline: Wrote `{string}` into GITINFO")
