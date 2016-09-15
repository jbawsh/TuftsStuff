(* James McCants *)
(* Comp105 - hw5 - ml - 11/11/15 *)
(* solution.sml *)


(* Problem A *)

(* Compound fuction *)

fun compound biop 0 x = x
| compound biop n x = biop (x, compound biop (n - 1) x)

(* Curried form for integer exponentiation *)

fun exp x 0 = 1
| exp x y = compound op* (y - 1) x


(* Problem B *)

(* Reverses a list using foldl *)

fun myrev xs = foldl op:: nil xs

(* Returns smallest value using foldl *)

fun minlist (x::xs) = foldl Int.min x xs
| minlist [] = raise Match


(* Problem C *)

(* Implements foldl with recursion *)

fun foldl f start [] = start
| foldl f start (x::xs) = foldl f (f (x, start)) xs

(* Implements foldr with recursion *)

fun foldr f start [] = start
| foldr f start (x::xs) = f (x, foldr f start xs)


(* Problem D *)

fun flatten (x::xs) = x @ (flatten xs)
| flatten [] = []


(* Problem E *)

exception EmptyList

fun mynth 0 (x::xs) = x
| mynth n (x::xs) = mynth (n - 1) xs
| mynth n [] = raise EmptyList


(* Problem F *)

fun pairfoldr f start ([], []) = start
| pairfoldr f start (x::xs, y::ys) = f (x, y, pairfoldr f start (xs, ys))
| pairfoldr f start _ = raise Match


(* Problem G *)

(* Pattern matching for trees of arithmetic expressions *)

datatype Exp = VAL of int 
             | BINARY of Op * Exp * Exp 
             | UNARY of Op * Exp
      and Op = PLUS | MINUS | TIMES | DIVIDE;

exception InvalidOp

(* I decided to comment this out because it was throwing errors sometimes and
   sometimes not, I hope this at least gives a general idea of what I was trying
   to do *)

(*
fun evalexp (VAL (x:int)) = x
| evalexp (BINARY (PLUS, x:Exp, y:Exp)) = (evalexp x) + (evalexp y)
| evalexp (BINARY (MINUS, x:Exp, y:Exp)) = (evalexp x) - (evalexp y)
| evalexp (BINARY (TIMES, x:Exp, y:Exp)) = (evalexp x) * (evalexp y)
| evalexp (BINARY (DIVIDE, x:Exp, y:Exp)) = (evalexp x) / (evalexp y)
| evalexp (UNARY (PLUS, x:Exp)) = evalexp x
| evalexp (UNARY (MINUS, x:Exp)) = 2 * (evalexp x)
| evalexp _ = raise InvalidOp

fun checkexp (VAL (x:int)) = true
| checkexp (BINARY (oper:Op, x:Exp, y:Exp)) = (checkexp x) && (checkexp y)
| checkexp (UNARY (TIMES, x:Exp)) = false
| checkexp (UNARY (DIVIDE, x:Exp)) = false
| checkexp (UNARY (oper:Op, x:Exp)) = (checkexp x)
| checkexp _ = false
*)