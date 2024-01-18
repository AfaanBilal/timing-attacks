Timing Attacks
==============

Author: **[Afaan Bilal](https://afaan.dev)**

## Introduction
An extremely basic demonstration of timing attacks in string comparisons.

### Run
```bash
gcc main.c -o main.exe && ./main.exe
```

```bash
STRING LENGTH: 1001
TRIALS:        1000000

[UNEQUAL][UNSAFE] Duration: 0.080000 seconds / 0080 cycles
[EQUAL  ][UNSAFE] Duration: 0.979000 seconds / 0979 cycles

[UNEQUAL][SAFE  ] Duration: 1.133000 seconds / 1133 cycles
[EQUAL  ][SAFE  ] Duration: 1.172000 seconds / 1172 cycles

Total: 3.365000 seconds / 3365 cycles
```

As can be seen in the output above, the unsafe comparison shows a big
difference (`899 clock cycles`) when comparing equal vs unequal strings
while as in the safe comparison, the difference is negligible (`30 clock cycles`).

---

## Contributing
All contributions are welcome. Please create an issue first for any feature request
or bug. Then fork the repository, create a branch and make any changes to fix the bug
or add the feature and create a pull request. That's it!
Thanks!

---

## License
**Timing Attacks** is released under the MIT License.
Check out the full license [here](LICENSE).
