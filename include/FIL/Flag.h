#define FIL_FLAG '-'

#pragma region GLOB

/// @brief -g
/// @see FIL_FLAG
#define FIL_FLAG_GLOB 'g'

/// @brief -gn
/// @see FIL_FLAG
/// @see FIL_FLAG_GLOB
#define FIL_FLAG_GLOB_NAME 'n'

/// @brief -gp
/// @see FIL_FLAG
/// @see FIL_FLAG_GLOB
#define FIL_FLAG_GLOB_PLNAME 'p'

/// @brief -gr
/// @see FIL_FLAG
/// @see FIL_FLAG_GLOB
#define FIL_FLAG_GLOB_PROFILE 'r'

/// @brief -gb
/// @see FIL_FLAG
/// @see FIL_FLAG_GLOB
#define FIL_FLAG_GLOB_BG 'b'

/// @brief -ge
/// @see FIL_FLAG
/// @see FIL_FLAG_GLOB
#define FIL_FLAG_GLOB_ETC 'e'

#pragma endregion

#pragma region ADV

/// @brief -a
/// @see FIL_FLAG
#define FIL_FLAG_ADV 'a'

#pragma region BROOD

/// @brief -ab
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
#define FIL_FLAG_ADV_BROOD 'b'

/// @brief -abn
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_BROOD
/// @see FIL_FLAG_GLOB_NAME
#define FIL_FLAG_ADV_BROOD_NAME FIL_FLAG_GLOB_NAME

/// @brief -abd
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_BROOD
#define FIL_FLAG_ADV_BROOD_DESC 'd'

/// @brief -abs
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_BROOD
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_BROOD_STAT FIL_FLAG_ADV_STAT

#pragma endregion

#pragma region INFO

/// @brief -ai
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
#define FIL_FLAG_ADV_INFO 'i'

/// @brief -aix
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_INFO
#define FIL_FLAG_ADV_INFO_GENDER 'x'

/// @brief -aia
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_INFO
#define FIL_FLAG_ADV_INFO_AGE 'a'

/// @brief -aih
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_INFO
#define FIL_FLAG_ADV_INFO_HEIGHT 'h'

/// @brief -aiw
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_INFO
#define FIL_FLAG_ADV_INFO_WEIGHT 'w'

/// @brief -aib
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_INFO
#define FIL_FLAG_ADV_INFO_BIAS 'b'

#pragma endregion

#pragma region STAT

/// @brief -as
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
#define FIL_FLAG_ADV_STAT 's'

/// @brief -asl
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_LP 'l'

/// @brief -ass
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_SP 's'

/// @brief -asi
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_INT 'i'

/// @brief -ast
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_STR 't'

/// @brief -asc
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_CON 'c'

/// @brief -asa
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_AGI 'a'

/// @brief -asg
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_G 'g'

/// @brief -asn
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
#define FIL_FLAG_ADV_STAT_LNK 'n'

/// @brief -asn0
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
/// @see FIL_FLAG_ADV_STAT_LNK
#define FIL_FLAG_ADV_STAT_LNK0 '0'

/// @brief -asn1
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
/// @see FIL_FLAG_ADV_STAT_LNK
#define FIL_FLAG_ADV_STAT_LNK1 '1'

/// @brief -asn2
/// @see FIL_FLAG
/// @see FIL_FLAG_ADV
/// @see FIL_FLAG_ADV_STAT
/// @see FIL_FLAG_ADV_STAT_LNK
#define FIL_FLAG_ADV_STAT_LNK2 '2'

#pragma endregion

#pragma endregion