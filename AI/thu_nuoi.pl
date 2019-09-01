thu_nuoi_trong_nha(X) :- thu_nuoi_nho(X).
thu_nuoi_nho(X) :- thu_nuoi(X) , nho(X).
thu_nuoi(X) :-  cho(X).
cho(X) :- cho_long_xu(X).
nho(X) :- cho_long_xu(X).
cho_long_xu(pluto).