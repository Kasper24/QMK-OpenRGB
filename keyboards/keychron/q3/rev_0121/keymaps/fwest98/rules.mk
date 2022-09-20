VIA_ENABLE = yes

UNICODEMAP_ENABLE = yes
CAPS_WORD_ENABLE = yes

RGB_MATRIX_ENABLE = yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif
