anh_ruot(X, Y) :- nam(X), cha(X1, X), cha(X1, Y), tuoi(X, T1), tuoi(Y, T2), T1 >= T2.
chi_ruot(X, Y) :- nu(X), cha(X1, X), cha(X1, Y), tuoi(X, T1), tuoi(Y, T2), T1 >= T2.
em_trai_ruot(X, Y) :- nam(X), cha(X1, X), cha(X1, Y), tuoi(X, T1), tuoi(Y, T2), T1 < T2.
em_gai_ruot(X, Y) :- nu(X), cha(X1, X), cha(X1, Y), tuoi(X, T1), tuoi(Y, T2), T1 < T2.
chu(X, Y) :- cha(Z, Y), em_trai_ruot(X, Z).
bac_trai(X, Y) :- cha(Z, Y), anh_ruot(X, Z).
cau(X, Y) :- me(Z, Y), em_trai_ruot(X, Z).
cau(X, Y) :- me(Z, Y), anh_ruot(X, Z).
co(X, Y) :- cha(Z, Y), chi_ruot(X, Z).
co(X, Y) :- cha(Z, Y), em_gai_ruot(X, Z).
di(X, Y) :- me(Z, Y), chi_ruot(X, Z).
di(X, Y) :- me(Z, Y), em_gai_ruot(X, Z).
mo(X, Y) :- cau(Z, Y), vo(X, Z).
thim(X, Y) :- chu(Z, Y), vo(X, Z).
bac_gai(X, Y) :- bac_gai(Z, Y), vo(X, Z).
ong_noi(X, Y) :- cha(Z, Y), cha(X, Z).
ong_ngoai(X, Y) :- me(Z, Y), cha(X, Z).
ba_noi(X, Y) :- cha(Z, Y), me(X, Z).
ba_ngoai(X, Y) :- me(Z, Y), me(X, Z).
cha_vo(X, Y) :- vo(Z, Y), cha(X, Z).
me_vo(X, Y) :- vo(Z, Y), me(X, Z).
cha_chong(X, Y) :- vo(Y, Z), cha(X, Z).
me_chong(X, Y) :- vo(Y, Z), me(X, Z).

vo(mary, peter).
vo(kelly, jason).
vo(betty, jason).
vo(susan, ben).
vo(daisy, steven).
vo(daisy, kevin).
vo(jesse, mark).
vo(alissa, ivan).

cha(peter, jason).
cha(peter, ben).
cha(peter, daisy).
cha(peter, mark).
cha(jason, bin).
cha(jason, michael).
cha(ben, jenifer).
cha(ben, jenny).
cha(steven, ivan).
cha(steven, alissa).
cha(steven, thomas).
cha(mark, tracy).
cha(mark, justin).

me(mary, jason).
me(mary, ben).
me(mary, daisy).
me(mary, mark).

me(kelly, bin).
me(kelly, michael).
me(susan, jenifer).
me(susan, jenny).

me(daisy, ivan).
me(daisy, alissa).
me(daisy, thomas).

me(jesse, tracy).
me(jesse, justin).

tuoi(mary, 68).
tuoi(peter, 70).
tuoi(kelly, 38).
tuoi(jason, 43).
tuoi(betty, 43).
tuoi(bin, 18).
tuoi(michael, 17).
tuoi(ben, 40).
tuoi(susan, 35).
tuoi(jenifer, 16).
tuoi(jenny, 15).
tuoi(steven, 50).
tuoi(daisy, 41).
tuoi(kevin, 55).
tuoi(ivan, 22).
tuoi(alissa, 20).
tuoi(thomas, 18).
tuoi(mark, 38).
tuoi(jesse, 38).
tuoi(tracy, 10).
tuoi(justin, 9).


nam(peter).
nam(jason).
nam(bin).
nam(michael).
nam(ben).
nam(steven).
nam(kevin).
nam(ivan).
nam(mark).
nam(justin).

nu(mary).
nu(kelly).
nu(betty).
nu(susan).
nu(jenifer).
nu(jenny).
nu(daisy).
nu(alissa).
nu(jesse).
nu(thomas).
nu(tracy).

 