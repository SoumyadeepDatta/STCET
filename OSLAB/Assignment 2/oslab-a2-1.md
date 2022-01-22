```sh
~$ vi teachers
~$ cat teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
T006 | M.D | Automata    | Howrah
T007 | P.P | NM          | Behala
T008 | T.D | Analog      | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T011 | S.D | SE          | Garia
T012 | T.R | IM          | Jadavpur
T013 | R.D | DSA         | Kolkata
T014 | S.R | CA          | Chetla
T015 | A.D | English     | Kolkata
T016 | P.D | Chemistry   | Howrah
T017 | S.M | Physics     | Jadavpur
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ head -3 teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
~$ ls -l -t | tail -1
-rw-r--r-- 1 user user   0 Sep 24 10:11 lab_2.x11
~$ ~$ ~$ 
~$ head -c 100 teacher
head: cannot open 'teacher' for reading: No such file or directory
~$ head -c 100 teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H ~$ 
~$ tail -3 teachers
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ tail +5 teachers
T005 | A.B | Chemistry   | Kolkata
T006 | M.D | Automata    | Howrah
T007 | P.P | NM          | Behala
T008 | T.D | Analog      | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T011 | S.D | SE          | Garia
T012 | T.R | IM          | Jadavpur
T013 | R.D | DSA         | Kolkata
T014 | S.R | CA          | Chetla
T015 | A.D | English     | Kolkata
T016 | P.D | Chemistry   | Howrah
T017 | S.M | Physics     | Jadavpur
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ cat>sh | head -5 teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
q
~$ cat sh
q
~$ head -5 teachers | cat>shortlist
~$ ls
lab_2.x11  sh  shortlist  teachers
~$ mv shortlist
mv: missing destination file operand after 'shortlist'
Try 'mv --help' for more information.
~$ rm shortlist
~$ ls
lab_2.x11  sh  teachers
~$ head -5 teachers | head -5 teachers | cat>shortlist
~$ cat shortlist
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
~$ rm shortlist
~$ ls
lab_2.x11  sh  teachers
~$ head -5 teachers | cat>shortlist | cat shortlist
~$ rm shortlist
~$ ls
lab_2.x11  sh  teachers
~$ head -5 teachers | cat>shortlist | echo

~$ rm shortlist
~$ ls
lab_2.x11  sh  teachers
~$ head -5 teachers | cat>shortlist & cat shortlist
[1] 1176
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
[1]+  Done                    head -5 teachers | cat > shortlist
~$ cat shortlist
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
~$ cut -d "|" -f 2,4 shortlist
 P.C | Kolkata
 K.M | Howrah
 J.S | Jadavpur
 A.H | Garia
 A.B | Kolkata
~$ cut -d "|" -f 3 shortlist | cat>cutlist1 & cat cutlist1
[1] 1262
~$ cat cutlist1
 DS              
 OS              
 Graphics        
 DSA     
 Chemistry       
[1]+  Done                    cut -d "|" -f 3 shortlist | cat > cutlist1
~$ rm cutlist1
~$ ls
lab_2.x11  sh  shortlist  teachers
~$ cut -d "|" -f 3 shortlist & cut -d "|" -f 3 shortlist | cat>cutlist1
[1] 1321
 DS              
 OS              
 Graphics        
 DSA     
 Chemistry       
[1]+  Done                    cut -d "|" -f 3 shortlist
~$ cat cutlist1
 DS              
 OS              
 Graphics        
 DSA     
 Chemistry       
~$ cut -d "|" -f 1,2,4 shortlist | cat>cutlist2
~$ cutlist2
bash: cutlist2: command not found
~$ rm cutlist2
~$ ls
cutlist1  lab_2.x11  sh  shortlist  teachers
~$ cut -d "|" -f 1,2,4 shortlist | cat>cutlist2
~$ cat cutlist2
T001 | P.C | Kolkata
T002 | K.M | Howrah
T003 | J.S | Jadavpur
T004 | A.H | Garia
T005 | A.B | Kolkata
~$ paste -d "|" cutlist1 cutlist2 > cutlist3
~$ cat cutlist3
 DS              |T001 | P.C | Kolkata
 OS              |T002 | K.M | Howrah
 Graphics        |T003 | J.S | Jadavpur
 DSA     |T004 | A.H | Garia
 Chemistry       |T005 | A.B | Kolkata
~$ man sort
~$ sort -k 2n teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
T006 | M.D | Automata    | Howrah
T007 | P.P | NM          | Behala
T008 | T.D | Analog      | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T011 | S.D | SE          | Garia
T012 | T.R | IM          | Jadavpur
T013 | R.D | DSA         | Kolkata
T014 | S.R | CA          | Chetla
T015 | A.D | English     | Kolkata
T016 | P.D | Chemistry   | Howrah
T017 | S.M | Physics     | Jadavpur
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ man sort
~$ sort -k 2 teachers
T005 | A.B | Chemistry   | Kolkata
T015 | A.D | English     | Kolkata
T004 | A.H | DSA         | Garia
T020 | A.K | CA          | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T003 | J.S | Graphics    | Jadavpur
T018 | K.B | COI         | Jadavpur
T002 | K.M | OS          | Howrah
T006 | M.D | Automata    | Howrah
T001 | P.C | DS          | Kolkata
T016 | P.D | Chemistry   | Howrah
T007 | P.P | NM          | Behala
T013 | R.D | DSA         | Kolkata
T011 | S.D | SE          | Garia
T017 | S.M | Physics     | Jadavpur
T014 | S.R | CA          | Chetla
T019 | S.R | DSA         | Howrah
T008 | T.D | Analog      | Behala
T012 | T.R | IM          | Jadavpur
~$ man sort
~$ sort -r teachers
T020 | A.K | CA          | Behala
T019 | S.R | DSA         | Howrah
T018 | K.B | COI         | Jadavpur
T017 | S.M | Physics     | Jadavpur
T016 | P.D | Chemistry   | Howrah
T015 | A.D | English     | Kolkata
T014 | S.R | CA          | Chetla
T013 | R.D | DSA         | Kolkata
T012 | T.R | IM          | Jadavpur
T011 | S.D | SE          | Garia
T010 | G.Y | OOP         | Kolkata
T009 | A.P | COA         | Howrah
T008 | T.D | Analog      | Behala
T007 | P.P | NM          | Behala
T006 | M.D | Automata    | Howrah
T005 | A.B | Chemistry   | Kolkata
T004 | A.H | DSA         | Garia
T003 | J.S | Graphics    | Jadavpur
T002 | K.M | OS          | Howrah
T001 | P.C | DS          | Kolkata
~$ vi numfile
~$ cat numfile
2
10
5
27
4
~$ sort numfile
10
2
27
4
5
~$ sort -n numfile
2
4
5
10
27
~$ cp teachers newfile
~$ cat newfile
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
T006 | M.D | Automata    | Howrah
T007 | P.P | NM          | Behala
T008 | T.D | Analog      | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T011 | S.D | SE          | Garia
T012 | T.R | IM          | Jadavpur
T013 | R.D | DSA         | Kolkata
T014 | S.R | CA          | Chetla
T015 | A.D | English     | Kolkata
T016 | P.D | Chemistry   | Howrah
T017 | S.M | Physics     | Jadavpur
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ cat teachers | tr [:lower:] [:upper:] | tr ["|"] ["~"]
T001 ~ P.C ~ DS          ~ KOLKATA
T002 ~ K.M ~ OS          ~ HOWRAH
T003 ~ J.S ~ GRAPHICS    ~ JADAVPUR
T004 ~ A.H ~ DSA         ~ GARIA
T005 ~ A.B ~ CHEMISTRY   ~ KOLKATA
T006 ~ M.D ~ AUTOMATA    ~ HOWRAH
T007 ~ P.P ~ NM          ~ BEHALA
T008 ~ T.D ~ ANALOG      ~ BEHALA
T009 ~ A.P ~ COA         ~ HOWRAH
T010 ~ G.Y ~ OOP         ~ KOLKATA
T011 ~ S.D ~ SE          ~ GARIA
T012 ~ T.R ~ IM          ~ JADAVPUR
T013 ~ R.D ~ DSA         ~ KOLKATA
T014 ~ S.R ~ CA          ~ CHETLA
T015 ~ A.D ~ ENGLISH     ~ KOLKATA
T016 ~ P.D ~ CHEMISTRY   ~ HOWRAH
T017 ~ S.M ~ PHYSICS     ~ JADAVPUR
T018 ~ K.B ~ COI         ~ JADAVPUR
T019 ~ S.R ~ DSA         ~ HOWRAH
T020 ~ A.K ~ CA          ~ BEHALA
~$ man grep
~$ grep -f teachers "Kolkata"
grep: Kolkata: No such file or directory
~$ grep -f "Kolkata" teachers
grep: Kolkata: No such file or directory
~$ cat teachers
T001 | P.C | DS          | Kolkata
T002 | K.M | OS          | Howrah
T003 | J.S | Graphics    | Jadavpur
T004 | A.H | DSA         | Garia
T005 | A.B | Chemistry   | Kolkata
T006 | M.D | Automata    | Howrah
T007 | P.P | NM          | Behala
T008 | T.D | Analog      | Behala
T009 | A.P | COA         | Howrah
T010 | G.Y | OOP         | Kolkata
T011 | S.D | SE          | Garia
T012 | T.R | IM          | Jadavpur
T013 | R.D | DSA         | Kolkata
T014 | S.R | CA          | Chetla
T015 | A.D | English     | Kolkata
T016 | P.D | Chemistry   | Howrah
T017 | S.M | Physics     | Jadavpur
T018 | K.B | COI         | Jadavpur
T019 | S.R | DSA         | Howrah
T020 | A.K | CA          | Behala
~$ grep -h "Kolkata" teachers
T001 | P.C | DS          | Kolkata
T005 | A.B | Chemistry   | Kolkata
T010 | G.Y | OOP         | Kolkata
T013 | R.D | DSA         | Kolkata
T015 | A.D | English     | Kolkata
~$ grep -c "Howrah" teachers
5
~$ grep -n "Jadavpur" teachers
3:T003 | J.S | Graphics  | Jadavpur
12:T012 | T.R | IM               | Jadavpur
17:T017 | S.M | Physics  | Jadavpur
18:T018 | K.B | COI      | Jadavpur
~$ ~$ 
```
