~$ touch empty1 empty2 empty3 empty4 empty5
~$ ls -l
total 3
-rw-r--r-- 1 user user 0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user 0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user 0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user 0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user 0 Sep 10 10:50 empty5
-rw-r--r-- 1 user user 0 Sep 10 10:49 os_a1.x11
~$ cat > text.txt
Soumyadeep Datta
20
169, Rifle Club East, Bansdroni, Kolkata - 700070        
~$ cat text.txt
Soumyadeep Datta
20
169, Rifle Club East, Bansdroni, Kolkata - 700070
~$ cp text.txt newtext.txt
~$ ls -l
total 5
-rw-r--r-- 1 user user  0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user  0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user  0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user  0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user  0 Sep 10 10:50 empty5
-rw-r--r-- 1 user user 70 Sep 10 10:57 newtext.txt
-rw-r--r-- 1 user user  0 Sep 10 10:50 os_a1.x11
-rw-r--r-- 1 user user 70 Sep 10 10:54 text.txt
~$ cat > matter.txt
matter is created. Matter contains 2 sentences.
~$ cat text.txt matter.txt > txtmat.txt
~$ cat txtmat.txt
Soumyadeep Datta
20
169, Rifle Club East, Bansdroni, Kolkata - 700070
matter is created. Matter contains 2 sentences.
~$ ls -l
total 7
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty5
-rw-r--r-- 1 user user  48 Sep 10 11:00 matter.txt
-rw-r--r-- 1 user user  70 Sep 10 10:57 newtext.txt
-rw-r--r-- 1 user user   0 Sep 10 10:50 os_a1.x11
-rw-r--r-- 1 user user  70 Sep 10 10:54 text.txt
-rw-r--r-- 1 user user 118 Sep 10 11:03 txtmat.txt
~$ rm text.txt
~$ ls -l
total 6
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty5
-rw-r--r-- 1 user user  48 Sep 10 11:00 matter.txt
-rw-r--r-- 1 user user  70 Sep 10 10:57 newtext.txt
-rw-r--r-- 1 user user   0 Sep 10 10:50 os_a1.x11
-rw-r--r-- 1 user user 118 Sep 10 11:03 txtmat.txt
~$ ls *.txt
matter.txt  newtext.txt  txtmat.txt
~$ mv newtext.txt oldtext.txt
~$ ls *.txt
matter.txt  oldtext.txt  txtmat.txt
~$ mkdir mydir
~$ ls -l
total 7
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty5
-rw-r--r-- 1 user user  48 Sep 10 11:00 matter.txt
drwxr-xr-x 2 user user   2 Sep 10 11:08 mydir
-rw-r--r-- 1 user user  70 Sep 10 10:57 oldtext.txt
-rw-r--r-- 1 user user   0 Sep 10 11:05 os_a1.x11
-rw-r--r-- 1 user user 118 Sep 10 11:03 txtmat.txt
~$ mv oldtext.txt matter.txt mydir
~$ ls *.txt
txtmat.txt
~$ cd mydir
~/mydir$ ls *.txt
matter.txt  oldtext.txt
~/mydir$ cd $HOME
~$ mkdir newdir
~$ ls -l
total 5
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty1
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty2
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty3
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty4
-rw-r--r-- 1 user user   0 Sep 10 10:50 empty5
drwxr-xr-x 2 user user   4 Sep 10 11:10 mydir
drwxr-xr-x 2 user user   2 Sep 10 11:16 newdir
-rw-r--r-- 1 user user   0 Sep 10 11:05 os_a1.x11
-rw-r--r-- 1 user user 118 Sep 10 11:03 txtmat.txt
~$ cp -a /mydir/. /newdir/
cp: cannot stat '/mydir/.': No such file or directory
~$ cp -a mydir/. newdir/
~$ cd newdir
~/newdir$ ls *.txt
matter.txt  oldtext.txt
~/newdir$ cd $HOME
~$ date +%D
09/10/21
~$ date +'%d%m%Y'
10092021
~$ date +'%d/%m/%Y'
10/09/2021
~$ who
~$ whoami
user
~$ ls -a
.                         .bash_profile  .fakexinerama         .ssh    empty4     txtmat.txt
..                        .bashrc        .jupyter-blobs-v0.db  .xpra   empty5
.:965400428-fakexinerama  .cache         .os_a1.x11-0.term     empty1  mydir
.Xauthority               .config        .smc                  empty2  newdir
.bash_history             .dbus          .snapshots            empty3  os_a1.x11
~$ tree -a
.
├── .:965400428-fakexinerama
├── .Xauthority
├── .bash_history
├── .bash_profile -> /home/user/.bashrc
├── .bashrc
├── .cache
│   └── mesa_shader_cache
│       ├── 6e
│       │   └── 3d8537c203221dd25dd2d1aa7e5e1a5fe58304
│       ├── b5
│       │   └── 62cbb87323bcad31735798abed1e64e9ad698f
│       └── index
├── .config
│   └── xpra
│       └── xpra.conf
├── .dbus
│   └── session-bus
│       └── c05500a2c1ca4fec9298c90b026b1874-965400428
├── .fakexinerama
├── .jupyter-blobs-v0.db
├── .os_a1.x11-0.term
├── .smc -> /tmp/.cocalc
├── .snapshots
│   └── 2021-09-10-110036
│       ├── .:965400428-fakexinerama
│       ├── .Xauthority
│       ├── .bash_history
│       ├── .bash_profile -> /home/user/.bashrc
│       ├── .bashrc
│       ├── .cache
│       │   └── mesa_shader_cache
│       │       ├── 6e
│       │       │   └── 3d8537c203221dd25dd2d1aa7e5e1a5fe58304
│       │       ├── b5
│       │       │   └── 62cbb87323bcad31735798abed1e64e9ad698f
│       │       └── index
│       ├── .config
│       │   └── xpra
│       │       └── xpra.conf
│       ├── .dbus
│       │   └── session-bus
│       │       └── c05500a2c1ca4fec9298c90b026b1874-965400428
│       ├── .fakexinerama
│       ├── .jupyter-blobs-v0.db
│       ├── .os_a1.x11-0.term
│       ├── .smc -> /tmp/.cocalc
│       ├── .snapshots
│       ├── .ssh
│       │   └── authorized_keys
│       ├── .xpra
│       │   └── project-bb5c73a1-3946-49b6-9d33-8fa3de7ee5c2-965400428
│       ├── empty1
│       ├── empty2
│       ├── empty3
│       ├── empty4
│       ├── empty5
│       ├── matter.txt
│       ├── newtext.txt
│       ├── os_a1.x11
│       └── text.txt
├── .ssh
│   └── authorized_keys
├── .xpra
│   └── project-bb5c73a1-3946-49b6-9d33-8fa3de7ee5c2-965400428
├── empty1
├── empty2
├── empty3
├── empty4
├── empty5
├── mydir
│   ├── matter.txt
│   └── oldtext.txt
├── newdir
│   ├── matter.txt
│   └── oldtext.txt
├── os_a1.x11
└── txtmat.txt

27 directories, 50 files
~$ who -q

# users=0
~$ cd newdir
~/newdir$ cd
~$ 
