/* PART 1 */

buy(M,O) :-
	sells(M,O),stock(M,O),!.

go(H,M) :-
	open(M),accessible(H,M,R),write('By using '),write(R),!.


shoppinglist(H,O1,O2,O3) :-
	(buy(market1,O1)
	  -> go(H,market1),write(' '),write(O1),write(' bought from market1'),nl
	  ;(buy(market2,O1) 
	  	-> go(H,market2),write(' '),write(O1),write(' bought from market2'),nl
	  	;(buy(market3,O1)
	  		-> go(H,market3),write(' '),write(O1),write(' bought from market3'),nl
	  		;(buy(market4,O1),write(O1),write(' unvailable in markets'),nl 
	  			->go(H,market4),write(' '),write(O1),write(' bought from market4'),nl
	  			;write(O1),write(' is unvaliable')),nl
	  		)
	  	)
	),
	(buy(market1,O2)
	  -> go(H,market1),write(' '),write(O2),write(' bought from market1'),nl
	  ;(buy(market2,O2)
	  	-> go(H,market2),write(' '),write(O2),write(' bought from market2'),nl
	  	;(buy(market3,O2)
	  		-> go(H,market3),write(' '),write(O2),write(' bought from market3'),nl
	  		;(buy(market4,O2),write(O2),write(' unvailable in markets'),nl
	  			->go(H,market4),write(' '),write(O2),write(' bought from market4'),nl
	  			;write(O2),write(' is unvailable')),nl
	  		)
	  	)
	),
	(buy(market1,O3)
	  -> go(H,market1),write(' '),write(O3),write(' bought from market1'),nl
	  ;(buy(market2,O3)
	  	-> go(H,market2),write(' '),write(O3),write(' bought from market2'),nl
	  	;(buy(market3,O3)
	  		-> go(H,market3),write(' '),write(O3),write(' bought from market3'),nl
	  		;(buy(market4,O3),write(O3),write(' unvailable in markets'),nl
	  			->go(H,market4),write(' '),write(O3),write(' bought from market4'),nl
	  			;write(O3),write(' is unvailable')),nl
	  		)
	  	)
	).


/* PART 2 */

travelcity(Start,Final):- connected(Start,Final), !.
		travelcity(Start,Final):- connected(Start,T),travelcity(T,Final).

