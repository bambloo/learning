# Username and Email
Before cloning a repo or pushing mods onto a branch, you need to setup your identifiers first.

```
git config --global [--set] user.name bambloo
git config --global [--set] user.email liugchome2004@163.com
```

Let's setup user.name to another

```
git config --global [--set] user.name eliu
git config --local user.name eliu
```

It seems useless on github, while git log shows:
```
commit da565b7500f84ef976525b3b1ab080142da8b5b0 (HEAD -> main, origin/main, origin/HEAD)
Author: eliu <liugchome2004@163.com>
Date:   Thu Feb 29 10:49:24 2024 +0800

    test commiter when user.name changed
```
Yep, revert it:
```
git config --global --set user.name bambloo
git config --local --unset user.name
```
Now, we can manipulate repositories.