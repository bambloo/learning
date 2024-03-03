# Turn a local directory into a Git Repository
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

## Remote
    git clone https://github.com/bambloo/learning.git

or with a directory named other than it's repo:

    git clone https://github.com/bambloo/learning.git bambloo-learning

The url of a repo can be `https://`, `git://` or `user@server:path/to/repo.git`.

## Local

    git clone /path/to/your/project /parth/to/another/location

# Deep in

Let's create a bare repo:

    mkdir ../test-git-init-bare
    cd ../test-git-init-bare
    git init --bare

clone it:

    cd ..
    git clone test-git-init-bare test-clone-bare-repo
    cd test-clone-bare-repo

test it:

    touch README.md
    git add README.md
    git commit -m "test push bare"
    git push

now direct into `.git/objects`

> test-clone-bare-repo/.git/objects  
> > 43/  c6/  fa/  info/  pack/
>
> test-git-init-bare/objects
> > 43/  c6/  fa/  info/  pack/

It's the same.

After, we create a repo manually:

    mkdir test-init-manual-repo
    cd test-init-manual-repo
    git init --bare .git

    touch README.md
    git add README.md

it's outcome:

    fatal: this operation must be run in a work tree

change `bare` in `.git/config` from true to false, and do it again:

    touch README.md
    git add README.md
    git commit -m "commit message"

Success! It tells that the only difference between bare and origin repos is whether it's code can be directly checkout.

It tells us, as long as you has a protocol who can access the file system directly, the git can be used to put your code under version controlling.