/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    MO(1)    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    _______  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI, _______ , KC_RALT  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  , S(KC_9)  ,S(KC_INT1),
    S(KC_DEL), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_INT3),
    S(KC_TAB), S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), _______  , S(KC_RALT), _______
  ),

  [2] = LAYOUT_universal(
    SSNP_FRE , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , KC_F12   ,
    SSNP_HOR , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

static const int OLED_W = 128;
static const int OLED_H = 32;
static const int PADDLE_WIDTH = 20;
// 移動方向フラグ
static bool move_right = false;
static bool move_left  = false;
// パドルX座標（ボールとの衝突判定で使用）
static int paddle_x = (OLED_W / 2) - 10;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_UP:   // 上矢印
            if (record->event.pressed) {
                move_right = true;
            } else {
                move_right = false;
            }
            return true;
  
        case KC_DOWN: // 下矢印
            if (record->event.pressed) {
                move_left = true;
            } else {
                move_left = false;
            }
            return true;
    }
    return true;
}

void oledkit_render_paddle(void) {
    // paddleのY座標
    const int PADDLE_Y = OLED_H - 1;
    // paddleが移動できる最大X座標
    const int MAX_X = OLED_W - PADDLE_WIDTH;
    // paddleの速さ
    const int PADDLE_SPEED = 6;

    if (move_right && paddle_x < MAX_X) {
        paddle_x += PADDLE_SPEED;
    }
    if (move_left && paddle_x > 0) {
        paddle_x -= PADDLE_SPEED;
    }
  
    // paddle（幅4、高さ1）の描画
    for (int i = 0; i < PADDLE_WIDTH; i++) {
        oled_write_pixel(paddle_x + i, PADDLE_Y, true);
    }
}

void oledkit_render_ball(void) {
    // ボールが10msで移動するドット数
    const int BALL_SPEED = 3;
    const int BALL_SPEED_MS = 10;
    const int MAX_Y = OLED_H - 1;
    const int CENTER_X = OLED_W / 2;
    const int BALL_RADIUS = 1;
    // ボールの初期位置
    const int INITIAL_BALL_Y = OLED_H / 2;

    static int velocity = BALL_SPEED;
    static int ball_y = INITIAL_BALL_Y;
    static uint32_t last_move_time = 0;
    uint32_t now = timer_read32();

    if (last_move_time == 0) {
        last_move_time = now;
    }
    if (timer_elapsed32(last_move_time) >= BALL_SPEED_MS) {
        last_move_time = now;
        ball_y += velocity;
        if (ball_y <= 0) {
            ball_y = 0;
            velocity = BALL_SPEED;
        } else if (ball_y >= MAX_Y) {
            // 床（パドル付近）に到達
            // ボールがy軸マイナス方向（下向き、velocity > 0）に進んでいるときのみパドル衝突で反転
            int ball_left  = CENTER_X - 1;
            int ball_right = CENTER_X + 1;
            int paddle_right = paddle_x + PADDLE_WIDTH - 1;
            bool hit_paddle = (velocity > 0) && (ball_right >= paddle_x && ball_left <= paddle_right);
            if (hit_paddle) {
                ball_y = MAX_Y;
                velocity = -BALL_SPEED;
            } else {
                // パドルに当たっていない、または上向きで来た → 初期位置に戻す
                ball_y = INITIAL_BALL_Y;
                velocity = BALL_SPEED;
            }
        }
    }

    for (int dx = -BALL_RADIUS; dx <= BALL_RADIUS; dx++) {
        for (int dy = -BALL_RADIUS; dy <= BALL_RADIUS; dy++) {
            int px = CENTER_X + dx;
            int py = ball_y + dy;
            if (py >= 0 && py <= MAX_Y) {
                oled_write_pixel(px, py, true);
            }
        }
    }
}

void oledkit_render_info_user(void) {
    // keyball_oled_render_keyinfo();
    // keyball_oled_render_ballinfo();
    // keyball_oled_render_layerinfo();
    oled_clear();
    oledkit_render_paddle();
    // 幅3x3のドットが x=64 上を y 方向に往復する表示を使う場合は以下に差し替え:
    oledkit_render_ball();
}
#endif
