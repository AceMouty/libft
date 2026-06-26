#include "libft.h"
#include <stdlib.h>

// delcare fn's below as static to not pollute global symbol table
// also, these are implementation details and should not be exposed
static size_t wordscount(char const *s, char c);
// delimiter-aware strlen
static size_t word_len(char const *s, char c);
static char *subword(char const *s, char c);
static void freesplit(char **split);

/*
* return an array of strings split on a delimiter (char c)
*/
char **ft_split(char const *s, char c) {
  char **split;
  size_t words;
  size_t i;

  /*
   * If the input string is NULL, there is nothing to split.
   * Return NULL to signal failure / invalid input.
   */
  if (s == NULL)
    return (NULL);

  /*
   * Count how many words/tokens exist in the string.
   * This lets us allocate the correct number of char * slots.
   *
   * We add 1 later because the returned array must end with NULL.
   */
  words = wordscount(s, c);

  /*
   * Allocate space for the array of strings.
   *
   * Example:
   * ft_split("hello world", ' ')
   *
   * split[0] -> "hello"
   * split[1] -> "world"
   * split[2] -> NULL
   *
   * So for 2 words, we need 3 slots.
   */
  split = malloc(sizeof(char *) * (words + 1));
  if (split == NULL)
    return (NULL);

  /*
   * i tracks which index in the split array we are filling.
   */
  i = 0;

  /*
   * Walk through the input string until we reach the null terminator.
   */
  while (*s) {
    /*
     * Skip over delimiter characters.
     *
     * This handles:
     * - delimiters at the beginning
     * - repeated delimiters
     * - delimiters between words
     *
     * Example:
     * ",,,hello"
     *
     * This loop moves s forward until it points at 'h'.
     */
    while (*s && *s == c)
      s++;

    /*
     * If we are not at the end of the string, then s now points
     * to the beginning of a word.
     */
    if (*s) {
      /*
       * Allocate and copy the current word.
       *
       * subword() copies characters from s until it reaches
       * either the delimiter c or the end of the string.
       */
      split[i] = subword(s, c);

      /*
       * If allocation failed while creating this word, free
       * every word we already allocated, then free the array.
       */
      if (split[i] == NULL) {
        /*
         * freesplit() expects the array to be NULL-terminated.
         * Since split[i] failed, set this slot to NULL so the
         * cleanup loop knows where to stop.
         */
        split[i] = NULL;
        freesplit(split);
        return (NULL);
      }

      /*
       * Move to the next slot in the result array.
       */
      i++;
    }

    /*
     * Move s past the current word.
     *
     * After this loop, s will either point to:
     * - a delimiter
     * - the end of the string
     */
    while (*s && *s != c)
      s++;
  }

  /*
   * The array of strings must end with a NULL pointer.
   * This is how callers know where the result ends.
   */
  split[i] = NULL;

  /*
   * Return the completed array of allocated strings.
   */
  return (split);
}

/*
 * delimiter-aware strlen
 *
 * Counts the length of one word.
 * It stops when it finds either:
 * - the delimiter c
 * - the null terminator '\0'
 *
 * Example:
 * word_len("hello,world", ',') returns 5.
 */
static size_t word_len(char const *s, char c) {
  size_t len;

  len = 0;
  while (s[len] && s[len] != c)
    len++;
  return (len);
}

/*
 * Frees a split array.
 *
 * This is used when allocation fails partway through ft_split.
 * At that point, some words may already have been allocated.
 *
 * The array must be NULL-terminated before calling this function.
 */
static void freesplit(char **split) {
  size_t i;

  i = 0;

  /*
   * Free every allocated string inside the array.
   */
  while (split[i]) {
    free(split[i]);
    i++;
  }

  /*
   * Free the array itself.
   */
  free(split);
}

/*
 * Creates a newly allocated copy of one word.
 *
 * s points to the beginning of the word.
 * c is the delimiter.
 *
 * This function copies until it reaches c or '\0'.
 */
static char *subword(char const *s, char c) {
  char *word;
  size_t len;
  size_t i;

  /*
   * Find out how many characters are in this word.
   */
  len = word_len(s, c);

  /*
   * Allocate enough memory for:
   * - len characters
   * - one null terminator
   */
  word = malloc(sizeof(char) * (len + 1));
  if (word == NULL)
    return (NULL);

  /*
   * Copy the word from s into the newly allocated buffer.
   */
  i = 0;
  while (i < len) {
    word[i] = s[i];
    i++;
  }

  /*
   * Null-terminate the new string.
   */
  word[i] = '\0';

  return (word);
}

/*
 * Counts how many words are in the string.
 *
 * A word is a sequence of characters that are not the delimiter.
 *
 * Example:
 * wordscount("hello,,world", ',') returns 2.
 *
 * Repeated delimiters do not create empty words.
 */
static size_t wordscount(char const *s, char c) {
  size_t count;
  int in_word;

  count = 0;

  /*
   * in_word is used like a boolean.
   *
   * 0 means: we are currently outside a word.
   * 1 means: we are currently inside a word.
   */
  in_word = 0;

  while (*s) {
    /*
     * If this character is not a delimiter and we were previously
     * outside a word, then this is the start of a new word.
     */
    if (*s != c && in_word == 0) {
      count++;
      in_word = 1;
    }

    /*
     * If this character is a delimiter, we are no longer inside
     * a word. This allows the next non-delimiter character to
     * start a new word.
     */
    else if (*s == c)
      in_word = 0;

    s++;
  }

  return (count);
}
