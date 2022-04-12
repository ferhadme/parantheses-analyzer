### Parantheses analyzer
Command line tool for checking balance of parantheses

```
$ make

$ ./pa '()'
Balanced parantheses

$ ./pa '{}[]()[]([[[]]]){([])}'
Balanced parantheses

$ ./pa '(({'
Unbalanced parantheses
(({
  ^

$ ./pa '())'
Unbalanced parantheses
())
  ^

$ ./pa '(1 + (2 * 4))'
Balanced parantheses

$ ./pa '(1 + (2 * 4)'
Unbalanced parantheses
(1 + (2 * 4)
           ^

$ ./pa '
if (true) {
	printf("true\n");
	return;
{}}{'
Unbalanced parantheses
if (true) {
	printf("true\n");
	return;
{}}{'
   ^

$ ./pa $(perl -e 'print "()" x 10000 . "\n";')
Balanced parantheses

$ ./pa $(perl -e 'print "()(" x 100 . "\n";')
Unbalanced parantheses
()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(()(
              ^
```
