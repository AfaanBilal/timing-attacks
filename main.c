/**
 * Timing Attacks
 *
 * @author Afaan Bilal
 * @link   https://afaan.dev
 * @copyright 2024 Afaan Bilal
 */

#include <stdio.h>
#include <time.h>

const int LENGTH = 1001;
const char *SECRET_PASSWORD =
    "FJDMeFZPCFqUwB6f4YrpRDH2TPZmdjSqxweKR9HCRf5VVSV5GR8Ydw6z0S6REP320knCm60AYD"
    "yL1vTFG67vL53nF4Z3uxRLKn1pj90LPDuScx0JDhh0iMNTLtv0mNcW0ZUmevbC75cLWmRmWyEd"
    "MGjx6DhxemGiq58ibPkraLPrKMMavvqYbmbxjwYSCpSGUEr5chUXjDYr8E1BkH52PW9vigr6uB"
    "D8gkPiJnU4Byf4Z71mBFySkVKgwvbnLKjdUbbPn9qBgpj7apgxvhxxTM6c7n2zcnaFmR45QmZ9"
    "f0XSqBD47MUJmjN1bHuHxiFEuL6DSJ8J0HycxP7nDEiq88Ti2uwEhP1R0zSJJGDQauwL3PD2HM"
    "Cw9n2VQTjCtcLJJVAybjuiHmHAEG12RFXRkCQV2LQxqGaU9NjNAVM05g7fJpkcQXXJGqXv0KGp"
    "6RiZ568JpGamQwADg7Ld6CVESNFJJSP5dVQyh93FYBUDjdVYZ0zTxDSMYeiRxTRERRrJtEeHJV"
    "qzBEYGkYg6fBY7ZyZpMTBBZGzrdtqrtJMMKNdej59zJXKuLFwPLPwTcpV6um6YcYDKng37gFrd"
    "cza461GT7SXW074KX898G06DWJ46XG729JgKGXBrUqmKkG7C1XX22CQqtMtLuKAhCmftHZLc0Z"
    "gR84yZHZW691NnWzjXH2fAHA6G1e93P01an3DhiMeJLuQLMAbjfqdfPKdH28pzDQHaNjW0QW8T"
    "1R6GFNkZT7RCxCMfK2krFMHTxKbw8tdfCYfxjeuCfdtyVHDR81fJh9g6RtNDLHAapakXVL3WRS"
    "KnNck8T7tu1Ex2K62y0DaeUDWRHTUR4yFcfEXR9EVbHFVXeanRYFzkw3VWpQhSqPL1Xnv6pec3"
    "qyt9ttm1u9KVYbNbLU7f1aUHh5r20cS2mg8b9Tbh0wzPkakZ8AG1BtE71G26QjuhnGbHjLEJ1A"
    "Piz09Fih2x1aqE9VzQWWQV9hbqdqybEBYuSijJ";
const char *TEST_A =
    "FJDMeFZPCFqUwB6f4YrpRDH2TPZmdjSqxweKR9HCRf5VVSV5GR8Ydw6z0S6REP320knCm60AYD"
    "tEB2wRLYwAGpPpVJ5eh9XkRJ8ZUuBkikPSGJHATjLA5BTB2X82qu8eaXiAavjWFn6KrgALv0BC"
    "6iV3rmf2FMgr6FnQ5VZ5h4iWcUh8K6GqVcpg743WLSkvNzW7TQc8Pqi1CAAFD9Ux03ywZydNb3"
    "vMwFKevHYgN560jHaCXDj8wfKZMcLmT4MbERUWvr6e3k6qnbzV33NneMqgiReafrN8nGgZdzXp"
    "NYQnTBpTMg6f5DDge0KaqB8YHxANj2u5Zq7kk2PrTgEwz6nruUX3WTmXWmLJ6YxYjZFYqrJqmS"
    "MV0925Pnhp1M389SC5rPxKL3P5e1HE4xCKyTfFZebCGzWJURZpph5SN6Hkw3W9gABT99cb8y6E"
    "hhRNZ95uJfPvr0VTBMmN3cpdb1a8x9KxnLx0zyKBYV9FVEuMuk0aFRk3Z6bFGh0hjX5PKrySuT"
    "agQ5MC9tC1Kr8te3yZWde34rbyQfjL61fLwddtTCW5ZXz2dfz09TipPWVMPe7kWHZaPkjWUPHd"
    "0qKAmAmv8p8YH5eReqQUSFuVEm1tH0Q6hD1PJwAXAJ7hb44jtaFM98HMX3pYfmf1j8m5rcFhaJ"
    "nuhTvGL2fH7EBmadwSya69K1gd7kXbB9x48bDa08T4iZfQzh0H9A6Z9aVjYYMx9R3EWDJuYnu0"
    "yr2QEXKb4QL2NLCMxzavbF4nEBNUKq42McF2Y5ncQS0bZQeAaR8u2cWL3tcWYMEBA5587Vkmi5"
    "i0L6q4k4tcmpwbRugt03E8cxLiC0YizSKdrB2F8PaN99208EDaCAhaH3U17q8Gyc5iYYQZE2w1"
    "XdEm9ewwWD4Pnfur3fTgbdtL0K0DDfr2ha1QjPL7VyQuHxwwTNQp5BvbZkMdUunciVL589jxku"
    "FSqufDFv2xitjBuq1gQ3CfRPmjBAWW3NkqLUyn";
const char *TEST_B =
    "FJDMeFZPCFqUwB6f4YrpRDH2TPZmdjSqxweKR9HCRf5VVSV5GR8Ydw6z0S6REP320knCm60AYD"
    "yL1vTFG67vL53nF4Z3uxRLKn1pj90LPDuScx0JDhh0iMNTLtv0mNcW0ZUmevbC75cLWmRmWyEd"
    "MGjx6DhxemGiq58ibPkraLPrKMMavvqYbmbxjwYSCpSGUEr5chUXjDYr8E1BkH52PW9vigr6uB"
    "D8gkPiJnU4Byf4Z71mBFySkVKgwvbnLKjdUbbPn9qBgpj7apgxvhxxTM6c7n2zcnaFmR45QmZ9"
    "f0XSqBD47MUJmjN1bHuHxiFEuL6DSJ8J0HycxP7nDEiq88Ti2uwEhP1R0zSJJGDQauwL3PD2HM"
    "Cw9n2VQTjCtcLJJVAybjuiHmHAEG12RFXRkCQV2LQxqGaU9NjNAVM05g7fJpkcQXXJGqXv0KGp"
    "6RiZ568JpGamQwADg7Ld6CVESNFJJSP5dVQyh93FYBUDjdVYZ0zTxDSMYeiRxTRERRrJtEeHJV"
    "qzBEYGkYg6fBY7ZyZpMTBBZGzrdtqrtJMMKNdej59zJXKuLFwPLPwTcpV6um6YcYDKng37gFrd"
    "cza461GT7SXW074KX898G06DWJ46XG729JgKGXBrUqmKkG7C1XX22CQqtMtLuKAhCmftHZLc0Z"
    "gR84yZHZW691NnWzjXH2fAHA6G1e93P01an3DhiMeJLuQLMAbjfqdfPKdH28pzDQHaNjW0QW8T"
    "1R6GFNkZT7RCxCMfK2krFMHTxKbw8tdfCYfxjeuCfdtyVHDR81fJh9g6RtNDLHAapakXVL3WRS"
    "KnNck8T7tu1Ex2K62y0DaeUDWRHTUR4yFcfEXR9EVbHFVXeanRYFzkw3VWpQhSqPL1Xnv6pec3"
    "qyt9ttm1u9KVYbNbLU7f1aUHh5r20cS2mg8b9Tbh0wzPkakZ8AG1BtE71G26QjuhnGbHjLEJ1A"
    "Piz09Fih2x1aqE9VzQWWQV9hbqdqybEBYuSijJ";

int timing_unsafe_compare(const char *s1, const char *s2, const int L) {
  for (int i = 0; i < L; i++) {
    if (s1[i] != s2[i])
      return 0;
  }

  return 1;
}

int timing_safe_compare(const char *s1, const char *s2, const int L) {
  int r = 1;

  for (int i = 0; i < L; i++) {
    if (s1[i] != s2[i])
      r = 0;
    else if (r != 0)
      r = 1;
  }

  return r;
}

const long TRIALS = 1000000;

int main() {
  clock_t start, end;
  double duration;
  int r;

  clock_t global_start = clock();

  printf("\nSTRING LENGTH: %d", LENGTH);
  printf("\nTRIALS:        %ld\n", TRIALS);

  printf("\n[UNEQUAL][UNSAFE] ");
  start = clock();
  for (int i = 0; i < TRIALS; i++) {
    timing_unsafe_compare(SECRET_PASSWORD, TEST_A, LENGTH);
  }
  end = clock();
  printf("Duration: %f seconds / %04ld cycles",
         (double)(end - start) / CLOCKS_PER_SEC, end - start);

  printf("\n[EQUAL  ][UNSAFE] ");
  start = clock();
  for (int i = 0; i < TRIALS; i++) {
    timing_unsafe_compare(SECRET_PASSWORD, TEST_B, LENGTH);
  }
  end = clock();
  printf("Duration: %f seconds / %04ld cycles",
         (double)(end - start) / CLOCKS_PER_SEC, end - start);

  printf("\n\n[UNEQUAL][SAFE  ] ");
  start = clock();
  for (int i = 0; i < TRIALS; i++) {
    timing_safe_compare(SECRET_PASSWORD, TEST_A, LENGTH);
  }
  end = clock();
  printf("Duration: %f seconds / %04ld cycles",
         (double)(end - start) / CLOCKS_PER_SEC, end - start);

  printf("\n[EQUAL  ][SAFE  ] ");
  start = clock();
  for (int i = 0; i < TRIALS; i++) {
    timing_safe_compare(SECRET_PASSWORD, TEST_B, LENGTH);
  }
  end = clock();
  printf("Duration: %f seconds / %04ld cycles",
         (double)(end - start) / CLOCKS_PER_SEC, end - start);

  clock_t global_end = clock();
  printf("\n\nTotal: %f seconds / %04ld cycles\n",
         (double)(global_end - global_start) / CLOCKS_PER_SEC,
         global_end - global_start);
}
