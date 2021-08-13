//
// Created by eisenmenger on 13.08.21.
//
#include "gmock/gmock.h"
#include "../Soundex.h"

using testing::Eq;


class SoundexEncoding : public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
    ASSERT_THAT(soundex.encode("B"), Eq("B000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}
