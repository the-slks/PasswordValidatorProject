# Password Strength Validator

**Author:** BOUBEKEUR MOHAMED SALAH EDDINE

## Description

This program checks how strong a password is.
It gives a score from 0 to 6 based on these rules:

- At least 8 characters
- At least one uppercase letter
- At least one lowercase letter
- At least one digit
- At least one special character (!#$%&*+-=?^_.)
- No spaces

The score is shown in color and it tells you exactly what is missing.

## How to compile

```
gcc -Wall projecto.c -o projecto

```

## How to run

```
./projecto
```

## Example

```
Enter password (or 'q' to quit): hello
Score: 2/6 [!] Weak -- significant improvements needed.
Missing requirements:
  - At least 8 characters (current: 5)
  - At least one uppercase letter
  - At least one digit
  - At least one special character (!#$%&*+-=?^_.)

Enter password (or 'q' to quit): H3llo_World!
Score: 6/6 [*] Very Strong -- excellent password.
All requirements satisfied.

Enter password (or 'q' to quit): q
```
