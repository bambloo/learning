# Download Container

Select a container of version you need from [Fedora-Container-Base](https://koji.fedoraproject.org/koji/packageinfo?packageID=26387)

In my case:
    curl https://kojipkgs.fedoraproject.org//packages/Fedora-Container-Base/39/20240328.0/images/Fedora-Container-Base-39-20240328.0.x86_64.tar.xz

After that *Extract layer.tar* from the tarball.

# Install

    wsl --import Fedora39 M:\wsl\fedora39 M:\wsl\fedora-39-rootfs.tar

# Config

automount linux partition on startup:

    REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run" /V "Mount PhysicalDrive3" /t REG_SZ /F /D "C:\Windows\System32\wsl.exe --mount \\.\PHYSICALDRIVE3 --partition 2"

edit /etc/wsl.conf under wsl:

    [automount]
    enabled=false
    mountFsTab=true

    [interop]
    appendWindowsPath = false

edit /etc/fstab:

    UUID=28e94946-3649-42d9-b6a4-4b458cd640e8       /home   ext4    defaults        0       2