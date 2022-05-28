# CustomVector

## Ištestuoti metodai

* emplace
* swap
* == operator
* shrink_to_fit
* crend


## CustomVector palyginimas su std::vector

| **std::vector**                             | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.0007458s.  | 0.00113s. | 0.0704703s.    | 0.716063s.     | 0.8136s.      |

| **CustomVector**                            | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.0001774s.  | 0.00113s. | 0.0070189s.    | 0.0894903s.     | 6.66528s.      |

## Antrosios užduoties std::vector pakeitimo CustomVector rezultatai

| **std::vector**                       | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 1.789s  |
| Perkistymai                           |   18    |

| **CustomVector**                      | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 2.356s  |
| Perkistymai                           |    17   |
