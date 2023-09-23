//
// Created by ryousuke kaga on 2023/09/23.
//

#include "cstring.h"
#include "munit.h"

#define TEST(name) MunitResult name(const MunitParameter params[], void* user_data_or_fixture)

TEST(test_string_init){
    string_t s;
    string_init(&s);
    munit_assert(s.len == 0);
}

TEST(test_string_init_macro) {
    string_t s = string("11111");
    munit_assert(s.len == 5);
    munit_assert(strcmp((char*)s.data, "11111") == 0);
}

TEST(test_string_copy) {
    string_t s1 = string("s1");
    string_t s2 = string("");

    string_cpy(&s2, &s1);
    munit_assert(strcmp((char*)s2.data, "s1") == 0);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_move) {
    string_t s1 = string("s1");
    string_t s2 = string("");

    string_mov(&s2, &s1);
    munit_assert(strcmp((char*)s2.data, "s1") == 0);
    munit_assert(s1.len == 0);
    munit_assert(s1.data == NULL);

    string_free(&s2);
}

TEST(test_string_cat) {
    string_t s1 = string("s1");
    string_t s2 = string("s2");

    string_cat(&s1, &s2);
    munit_assert(strcmp((char*)s1.data, "s1s2") == 0);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_cmp) {
    string_t s1 = string("s1");
    string_t s2 = string("s1");
    munit_assert(string_cmp(&s1, &s2) == 0);

    s1 = string("s1");
    s2 = string("s2");
    munit_assert(string_cmp(&s1, &s2) == -1);
}

MunitTest tests[] = {
        {
          "string_init",
          test_string_init,
          NULL,
          NULL,
          MUNIT_TEST_OPTION_NONE,
          NULL
        },
        {
            "string_init_macro",
            test_string_init_macro,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "string_copy",
            test_string_copy,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "string_move",
            test_string_move,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "string_cat",
            test_string_cat,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
                "string_cmp",
                test_string_cmp,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
            },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
        "cstring-test", /* name */
        tests, /* tests */
        NULL, /* suites */
        100, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}