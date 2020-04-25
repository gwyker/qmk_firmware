# Format a QMK Configurator keymap to something readable
import json
import sys
import pyperclip
from pprint import pprint

BASE_TEMPLATE = """    [0] = LAYOUT_kc(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
              ;        ;        ;        ;        ;        ;                                   ;        ;        ;        ;        ;        ;
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              ;        ;        ;        ;        ;        ;                                   ;        ;        ;        ;        ;        ;
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
              ;        ;        ;        ;        ;        ;                                   ;        ;        ;        ;        ;        ;
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              ;        ;        ;        ;        ;        ;        ;                 ;        ;        ;        ;        ;        ;        ;
//   └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                             ;        ;        ;                          ;        ;        ;
//                                  └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
"""
DEFINES = {
    'KC_TRNS': '____',

    'KC_F13': 'MAGICTAB',

    'LALT_T(KC_TAB)': 'ALT_TAB',
    'LCTL_T(KC_ESC)': 'CTL_ESC',
    'RCTL_T(KC_ENT)': 'rCTL_ENT',
    'LGUI_T(KC_BSPC)': 'GUI_BSPC',

    'LGUI(KC_TAB)': 'G_TAB',
    'LGUI(KC_GRV)': 'G_GRV',
    'LGUI(KC_1)': 'G_1',
    'LGUI(KC_2)': 'G_2',
    'LGUI(KC_3)': 'G_3',
    'LGUI(KC_4)': 'G_4',
    'LGUI(KC_5)': 'G_5',

    'LT(7,KC_BSPC)': '_7_BSPC',
    'LT(2,KC_SPC)': '_2_SPC',
    'LT(1,KC_SPC)': '_1_SPC',
    'LT(6,KC_ENT)': '_6_ENT',
    'LT(8,KC_EQL)': '_8_EQL',

    'TG(4)': 'GAME',
    'TG(5)': 'MOUSE',
    'TG(8)': 'ARROW',
}
ROW_LENGTHS = [12, 12, 12, 14, 6]


def format_layer(layer, label):
    """
    Loop through each element of the layer.
    Replaces any DEFINES and writes the keycode into the 8 cells before each comma.
    """
    template = BASE_TEMPLATE.replace('0', label)
    last_pos = -1
    for i, code in enumerate(layer):
        if code in DEFINES:
            code = DEFINES[code]
        else:
            if code.startswith('KC_'):
                code = code[3:]
        if len(code) > 8:
            raise AttributeError(f'{code} is too long.')
        # Get code text
        pos = template.find(';', last_pos+1)
        template = template[:pos-8] + f'{code:^8}' + template[pos:]
        last_pos = pos
        if template.find(';', pos+1) == -1:
            template = template[:pos]+' '+template[pos+1:]
            break
    template = template.replace(';',',')
    return template


def format(keymap):
    layer_texts = []
    for i, layer in enumerate(keymap['layers']):
        if len(layer) == 0:
            layer = ['KC_TRNS'] * 56
        layer_texts.append(format_layer(layer, str(i)))
    output = ''.join(layer_texts)
    last_comma = output.rfind(',')
    output = output[:last_comma] + output[last_comma+1:]
    return output


def main(filepath):
    with open(filepath, 'r') as f:
        keymap = json.load(f)
    output = format(keymap)
    pyperclip.copy(output)
    return output


if __name__ == '__main__':
    main(sys.argv[1])
