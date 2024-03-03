# Add file to cache

In order to begin tracking a new file, you use the command git add. To begin tracking the README file, you can run this:

    echo "# Hello" > README.md
    git add README.md

If you run your status command again, you can see that your README file is now tracked and staged to be committed:

    $ git status
    On branch master
    Your branch is up-to-date with 'origin/master'.
    Changes to be committed:
    (use "git restore --staged <file>..." to unstage)

        new file:   README.md

As a result, `.git/objects/fe/c56017dc1b1ac87ad6e54e3cb3a20bb8dcc5ab` appears.

## Deep in

The path to object file is calculated by `hash_object_body` in `object-file.c`. Every file you added is located at `.git/objects/{first two chars of object-id}/{ending chars of object-id}`, with it's content deflated by `write_loose_object` in `object-file.c` using `zlib`.

Let's take a look at the index file:

    4449 5243 0000 0002 0000 0001 65e4 6d6f
    1521 d724 65e4 6d6f 1531 1d4c 0000 0000
    0000 0000 0000 81a4 0000 0000 0000 0000
    0000 0008 fec5 6017 dc1b 1ac8 7ad6 e54e
    3cb3 a20b b8dc c5ab 0009 5245 4144 4d45
    2e6d 6400 335b afed 48de 3215 42cd d9ed
    7c7d 938e a5d0 6e54 

We can see the filename - README.md followed by it's object id. 

# Short Status
While the git status output is pretty comprehensive, it’s also quite wordy. Git also has a short status flag so you can see your changes in a more compact way. If you run git status -s or git status --short you get a far more simplified output from the command:

    $ git status -s
    A README.md

# Viewing Your Staged and Unstaged Changes

git diff shows you the exact lines added and removed — the patch, as it were.

    $ git diff --cached README.md
    diff --git a/README.md b/README.md
    new file mode 100644
    index 0000000..fec5601
    --- /dev/null
    +++ b/README.md
    @@ -0,0 +1 @@
    +# Hello

# Committing Your Changes

The simplest way to commit is to type git commit:

    $ git commit

Or with a commit message:

    $ git commit -m "Test commit"

add `-a` option to automatically add files already tracked.

## Deep in

After commit, there was a commit-object located at `objects/2e/e874a3bc828e0b4b0a720c3cbbb8473edc7c93` and a index-object at `objects/89/807efe1600c4786b7f695c30a8d13438baf314`.

see:
* `prepare_index` in `commit.c`
* `commit_tree_extended` in `commit.c`

# Remove File From Cache

    git rm --cached README.md

# Move File

    git mv README.md README

# Commit History

    $ git log --stat --patch
    commit 5f4a23c325cb4c4f54dfed80325b0968924921bd (HEAD -> master)
    Author: Eric Liu <liugchome2004@163.com>
    Date:   Sun Mar 3 23:58:24 2024 +0800

        Test commit

--stat:

    ---
    README.md | 1 +
    1 file changed, 1 insertion(+)

--patch:

    diff --git a/README.md b/README.md
    new file mode 100644
    index 0000000..fec5601
    --- /dev/null
    +++ b/README.md
    @@ -0,0 +1 @@
    +# Hello

oneline option:

    $ git log --oneline
    5f4a23c (HEAD -> master) Test commit

    $ git log --pretty=oneline
    5f4a23c325cb4c4f54dfed80325b0968924921bd (HEAD -> master) Test commit

Filt by file:

    $ git log -- path/to/file

## Some useful options:
| Option            | Description
|:----------        |:------------------------------
|  \-\<n\>          | Show only the last n commits.
|--since, --after   |Limit the commits to those made after the specified date.
|--until, --before  |Limit the commits to those made before the specified date.
|--author           |Only show commits in which the author entry matches the specified string.
|--committer        |Only show commits in which the committer entry matches the specified string.
|--grep             |Only show commits with a commit message containing the string.
|-S                 |Only show commits adding or removing code matching the string.