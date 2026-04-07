#include <emscripten/emscripten.h>
#include <cstdlib>
#include <ctime>

static int secret = 0;
static int attempts = 0;
static const int MAX_ATTEMPTS = 7;

extern "C" {

EMSCRIPTEN_KEEPALIVE
void new_game() {
    srand((unsigned int)time(0));
    secret = rand() % 100 + 1;
    attempts = 0;
}

EMSCRIPTEN_KEEPALIVE
int make_guess(int guess) {
    if (attempts >= MAX_ATTEMPTS) return -99;
    attempts++;
    if (guess < secret)  return -1;
    if (guess > secret)  return  1;
    return 0;
}

EMSCRIPTEN_KEEPALIVE
int get_attempts() {
    return attempts;
}

EMSCRIPTEN_KEEPALIVE
int get_secret() {
    return secret;
}

EMSCRIPTEN_KEEPALIVE
int get_max_attempts() {
    return MAX_ATTEMPTS;
}

}