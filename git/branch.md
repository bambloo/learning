# Description

Detailed information of branch is descibed on [Official Website](https://www.git-scm.com/book/en/v2/Git-Branching-Branches-in-a-Nutshell) or in branch-commit section.

> To really understand the way Git does branching, we need to take a step back and examine how Git stores its data.
>
> As you may remember from What is Git?, Git doesn’t store data as a series of changesets or differences, but instead as a series of snapshots.
>
> When you make a commit, Git stores a commit object that contains a pointer to the snapshot of the content you staged. This object also contains the author’s name and email address, the message that you typed, and pointers to the commit or commits that directly came before this commit (its parent or parents): zero parents for the initial commit, one parent for a normal commit, and multiple parents for a commit that results from a merge of two or more branches.
>
> To visualize this, let’s assume that you have a directory containing three files, and you stage them all and commit. Staging the files computes a checksum for each one (the SHA-1 hash we mentioned in What is Git?), stores that version of the file in the Git repository (Git refers to them as blobs), and adds that checksum to the staging area:
>
>  ```
>  $ git add README test.rb LICENSE
>  $ git commit -m 'Initial commit'
>  ```
> When you create the commit by running git commit, Git checksums each subdirectory (in this case, just the root project directory) and stores them as a tree object in the Git repository. Git then creates a commit object that has the metadata and a pointer to the root project tree so it can re-create that snapshot when needed.
>
> Your Git repository now contains five objects: three blobs (each representing the contents of one of the three files), one tree that lists the contents of the directory and specifies which file names are stored as which blobs, and one commit with the pointer to that root tree and all the commit metadata.

# Create a new branch

branch is actually a new pointer to the same commit you’re currently on.

    git branch branch_name

The git branch command only `created` a new branch — it `didn’t` switch to that branch.

    git log --oneline --decorate
    2e1de6d (HEAD -> master, hello) a.txt
# Check out another branch

    git checkout ${branch_name}

This operation will update index and checkout the file you commited. If you run `git checkout` with `-b` switch, it will  create a new branch and switch to it at the same time.

# History

    git log --oneline --decorate --graph --all

    * 673fbe8 (nb) c.txt
    | * c273e77 (HEAD -> master) c.txtx
    |/
    * eb2e305 b.txt
    * 2e1de6d a.txt

# Delete a branch

    git branch --delete ${branch_name}

# Merge branches

    git merge ${branch_to_be_merged}

and use graphical tool to solve conflicts:

    git mergetool

# Rename branch

    git branch --move ${old_branch_name} ${new_branch_name}
    git push --set-upstream origin new-branch-name
    git push origin --delete bad-branch-name