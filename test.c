//
// Created by ryousuke kaga on 2023/09/23.
//

#include "cstring.h"
#include "deps/munit/munit.h"

#define TEST(name) MunitResult name(const MunitParameter params[], void* user_data_or_fixture)

TEST(test_string_init){
    string_t s;
    string_init(&s);
    munit_assert(s.len == 0);
}

TEST(test_string_cmp) {
    string_t s1 = string("s1");
    string_t s2 = string("s1");
    munit_assert(string_cmp(&s1, &s2) == 0);
    s1 = string("s1");
    s2 = string("s2");
    munit_assert(string_cmp(&s1, &s2) == -1);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_init_macro) {
    string_t s = string("11111");
    munit_assert(s.len == 5);
    munit_assert(strcmp((char*)s.data, "11111") == 0);

    string_free(&s);
}

TEST(test_string_cpy) {
    string_t s1 = string("s1");
    string_t s2 = string("");

    string_cpy(&s2, &s1);
    munit_assert(string_cmp(&s1, &s2) == 0);
    munit_assert(s2.len == s1.len);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_mov) {
    string_t s1 = string("s1");
    string_t s2 = string("");

    string_mov(&s2, &s1);
    munit_assert(strcmp((char*)s2.data, "s1") == 0);
    munit_assert(s2.len == 2);
    munit_assert(s1.len == 0);
    munit_assert(s1.data == NULL);

    string_free(&s2);
}

TEST(test_string_cat) {
    string_t s1 = string("s1");
    string_t s2 = string("s2");

    string_cat(&s1, &s2);
    munit_assert(strcmp((char*)s1.data, "s1s2") == 0);
    munit_assert(s1.len = 4);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_ncmp) {
    string_t s1 = string("s1");
    string_t s2 = string("s1");
    munit_assert(string_ncmp(&s1, &s2, 2) == 0);
    s1 = string("s1");
    s2 = string("s2");
    munit_assert(string_ncmp(&s1, &s2, 1) == 0);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_ncpy) {
    string_t s1 = string("s1");
    string_t s2 = string("");

    string_ncpy(&s2, &s1, 1);
    munit_assert(string_ncmp(&s1, &s2, 1) == 0);
    munit_assert(s2.len == 1);

    string_free(&s1);
    string_free(&s2);
}

TEST(test_string_ncat) {
    string_t s1 = string("s1");
    string_t s2 = string("s2");

    string_ncat(&s1, &s2, 1);
    munit_assert(strcmp((char*)s1.data, "s1s") == 0);
    munit_assert(s1.len = 3);

    string_free(&s1);
    string_free(&s2);
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
                "string_cmp",
                test_string_cmp,
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
            "string_cpy",
            test_string_cpy,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "string_mov",
            test_string_mov,
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
                "string_ncmp",
                test_string_ncmp,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "string_ncpy",
                test_string_ncpy,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "string_ncat",
                test_string_ncat,
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
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}