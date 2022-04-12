### Parantheses analyzer
Command line tool for checking balance of parantheses

```sh
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
```
