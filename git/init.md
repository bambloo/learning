# Turn a Local directory into a Git Repository
Change current directory to your project:

    cd my_project
type:

    git init
This creates a new subdirectory named `.git` that contains all of your necessary repository files. Then start version-controlling with a few `git add` command that specify the files you want to track.

    git add *.c
    git add README.md
    git add LICENSE

Followed by a `git commit`:

    git commit -m "initialize repository"

Let's check with:

    git log
with output:
    
    commit 11e7fbe298c36df2641c81fa16bbd4a58d0f6387 (HEAD -> master)
    Author: Eric Liu <liugchome2004@163.com>
    Date:   Fri Mar 1 21:45:21 2024 +0800
        test

# Clone an Existing Repo

    git clone https://github.com/bambloo/learning.git

or with a directory named other than it's repo:

    git clone https://github.com/bambloo/learning.git bambloo-learning

The url of a repo can be `https://`, `git://` or `user@server:path/to/repo.git`.
