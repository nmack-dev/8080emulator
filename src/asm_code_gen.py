def asm_to_code(file):
    f = open('asm_cmds.txt', 'r')
    for line in f:
        if (line[0] is not '\\'):
            code_str = 'case '
            code_str += line[0:4] + ': printf(\"'

            if (line[9] is not '-'):
                code_str += line[9:12]
            
            else:
                code_str += 'NOP'
                
            print(code_str)


if __name__ == '__main__':
    asm_to_code('asm_cmds.txt')