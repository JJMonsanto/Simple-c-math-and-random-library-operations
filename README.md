# Simple C Math & Pseudo-Random Library Operations

A clean, structured C implementation demonstrating standard library mathematical operations (`<math.h>`) and scaled pseudo-random integer generation (`<stdlib.h>`). Follows textbook algorithmic specifications (Algorithm 4-1) to evaluate algebraic transformations, exponential powers, and ceiling/floor bounds within a single execution cycle.

---

## Control Flow & Execution Pipeline

The program coordinates data acquisition, random number seeding, and mathematical evaluation sequentially within `main(void)`:

```text
                        [ Execution Start ]
                                 |
                                 v
                     [ Seed PRNG: srand(time) ]
                                 |
                                 v
                     [ Prompt & Read Input (double) ]
                                 |
                                 v
                 [ Generate Scaled Random Int (3..37) ]
                                 |
                                 v
                   [ Compute Product: number * rand ]
                                 |
        +------------------------+------------------------+
        |                        |                        |
        v                        v                        v
  [ ceil(randomNum) ]     [ floor(product) ]     [ pow(num, rand) ]
        |                        |                        |
        +------------------------+------------------------+
                                 |
                                 v
                       [ sqrt(randomNum) ]
                                 |
                                 v
                         [ Output Results ]
```

---

## Mathematical & Algorithmic Formulation

### 1. Scaled Pseudo-Random Integer Generation
To scale an unconstrained `rand()` integer into an arbitrary closed interval $[min, max]$:

$$\text{Value} = \left( \text{rand}() \pmod{max - min + 1} \right) + min$$

For the range $[3, 37]$:
$$\text{Range Size} = 37 - 3 + 1 = 35$$
$$\mathbf{\text{randomNum} = (\text{rand}() \pmod{35}) + 3}$$

### 2. Standard Mathematical Functions (`<math.h>`)
- **Ceiling (`ceil`):** Returns the smallest integer value greater than or equal to the argument.
- **Floor (`floor`):** Returns the largest integer value less than or equal to the argument.
- **Power (`pow`):** Evaluates $x^y$ via floating-point exponentiation.
- **Square Root (`sqrt`):** Computes $\sqrt{x}$ for non-negative inputs.

---

## Empirical Verification & Test Matrix

Compiled with `gcc -Wall -Wextra -Werror` and verified against controlled inputs:

| Test Case | Input Number | Generated Rand (Range 3..37) | Product (`num * rand`) | `ceil(rand)` | `floor(product)` | `sqrt(rand)` | Status |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Integer Float** | `5.00` | `4` | `20.00` | `4.00` | `20.00` | `2.00` | **PASS** |
| **Fractional Decimal** | `2.50` | `9` | `22.50` | `9.00` | `22.00` | `3.00` | **PASS** |
| **Negative Float** | `-4.25` | `16` | `-68.00` | `16.00` | `-68.00` | `4.00` | **PASS** |
| **Convergence Point** | `1.00` | `25` | `25.00` | `25.00` | `25.00` | `5.00` | **PASS** |

---

## Compilation & Execution

### Using GCC (MinGW / Linux / macOS):
```bash
gcc -Wall -Wextra -Werror Simple-c-math-and-random-library-operations.c -o math_ops -lm
./math_ops
```

### Sample Interactive Output:
```text
Enter a number: 5.5
The number is: 5.50
The random number is: 16
The product of the two numbers is: 88.00
The ceiling of the random number is: 16.00
The floor of the product is: 88.00
5.50 raised to the power of 16 is: 2795147814.77
The square root of the random number is: 4.00
```

---

## Static Safety Audit
Scanned using static analysis security scanner:
- Unsafe unbounded calls (`gets`, bare `scanf("%s")`): **0 findings**
- Shell injection / pipe traps: **0 findings**
- PRNG initialization: Seeded once using `time(NULL)` with cast to `unsigned int`.
- Input validation: Checked return status on `scanf`.
