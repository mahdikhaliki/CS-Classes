%Team: The Curly Brackets

%X is ahead of Y
ahead(X, Y, [X, Y|_]).
ahead(X, Y, [_|T]) :- ahead(X, Y, T).

first(X, [X|_]).
second(X, [_, X, _, _, _]).
third(X, [_, _, X, _, _]).

notFirst(X, L) :- not(first(X, L)).
lastPlace(X, [_, _, _, _, X]).
fiveTeams([_, _, _, _, _]).


%College, Lead, Language, Color, Sponsor
winners(First, Second) :-
fiveTeams(Teams),
first(First, Teams),
second(Second, Teams),

ahead(team(_, _, _, blue, _), team(_, _, _, purple, _), Teams),
ahead(team(_, _, _, orange, _), team(_, _, haskell, _, _), Teams),
third(team(_, _, _, _, ibm), Teams),
ahead(team(_, _, python, _, _), team(_, _, _, blue, _), Teams),
notFirst(team(_, _, _, red, _), Teams),
ahead(team(_, _, _, _, google), team(_, _, _, blue, _), Teams),
ahead(team(_, _, haskell, _, _), team(_, _, javascript, _, _), Teams),
lastPlace(team(_, _, cplusplus, _, _), Teams),


member(team(sjsu, tammy, _, _, _), Teams),
member(team(_, alex, java, _, _), Teams),
member(team(_, justin, _, _, amazon), Teams),
member(team(sjsu, _, _, _, facebook), Teams),
member(team(foothill, _, _, _, ibm), Teams),
member(team(_, nicole, _, _, google), Teams),
member(team(foothill, _, javascript, _, _), Teams),
member(team(berkeley, _, _, orange, _), Teams),
member(team(_, _, _, red, apple), Teams),
member(team(ucsc, _, _, purple, _), Teams),
member(team(sjsu, _, _, blue, _), Teams).



solution(Teams) :-
fiveTeams(Teams),

ahead(team(_, _, _, blue, _), team(_, _, _, purple, _), Teams),
ahead(team(_, _, _, orange, _), team(_, _, haskell, _, _), Teams),
third(team(_, _, _, _, ibm), Teams),
ahead(team(_, _, python, _, _), team(_, _, _, blue, _), Teams),
notFirst(team(_, _, _, red, _), Teams),
ahead(team(_, _, _, _, google), team(_, _, _, blue, _), Teams),
ahead(team(_, _, haskell, _, _), team(_, _, javascript, _, _), Teams),
lastPlace(team(_, _, cplusplus, _, _), Teams),

member(team(_, steven, _, _, _), Teams),
member(team(deanza, _, _, _, _), Teams),

member(team(sjsu, tammy, _, _, _), Teams),
member(team(_, alex, java, _, _), Teams),
member(team(_, justin, _, _, amazon), Teams),
member(team(sjsu, _, _, _, facebook), Teams),
member(team(foothill, _, _, _, ibm), Teams),
member(team(_, nicole, _, _, google), Teams),
member(team(foothill, _, javascript, _, _), Teams),
member(team(berkeley, _, _, orange, _), Teams),
member(team(_, _, _, red, apple), Teams),
member(team(ucsc, _, _, purple, _), Teams),
member(team(sjsu, _, _, blue, _), Teams).