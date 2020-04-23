import sys
structure = """
	[4] = LAYOUT(
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        KC_TAB, _______, _______, _______, _______, _______,             _______, _______, _______, _______, KC_P, _______,
        KC_LCTL, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, _______,         KC_ESC, _______, _______, _______, _______, _______, _______,
                                KC_LALT, KC_SPC, MO(1),     MO(2), _______, KC_ENT
    ),
"""
columns = [
    0, 1, 2, 3, 4, 5,          9, 10, 11, 12, 13, 14,
    0, 1, 2, 3, 4, 5,          9, 10, 11, 12, 13, 14,
    0, 1, 2, 3, 4, 5,          9, 10, 11, 12, 13, 14,
    0, 1, 2, 3, 4, 5, 6,    8, 9, 10, 11, 12, 13, 14,
                4, 5, 6,    8, 9, 10]

layers = []

with open(sys.argv[1], 'r') as f:
    for line in f.readlines():
        if 'LAYOUT' not in line:
            continue
        layers.append(line.replace('KC_TRNS', '_______').split('LAYOUT(')[1][:-2].split(', '))
column_widths = [
    max([
        max([
            len(kc)
            if columns[i] == n
            else 6
            for i, kc in enumerate(layer)
        ])
        for layer in layers
    ])
    for n in range(15)
]

output = []
# with open(sys.argv[1], 'r') as f:
for i, layer in enumerate(layers):
    column_widths = [
        max([
            len(kc)+2
            if columns[i] == n
            else 8
            for i, kc in enumerate(layer)
        ])
        for n in range(15)
    ]
    output.append(f'[{i}] = LAYOUT(')
    last_col = 0
    line = '        '
    for j, kc in enumerate(layer):
        col = columns[j]
        if last_col > col:
            output.append(line)
            line = '        '
            last_col = 0
        col_diff = col-last_col-1
        if col_diff > 0:
            line += ' '*8*col_diff
        if i == len(layers)-1 and j == len(layer)-1:
            line += kc + ')'
        else:
            line += f'{kc},'.ljust(column_widths[col])
        last_col = col
    output.append(line)

for o in output:
    print(o)
