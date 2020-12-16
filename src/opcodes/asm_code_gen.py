import csv

# A function that converts a csv file into C code to implement assembly commands
def csv_to_code(file, alt):
    rows = [] 

    # Opens file as a csvreader object and obtains csv rows
    with open(file, 'r') as csvfile: 
        csvreader = csv.reader(csvfile) 
        next(csvreader) 
    
        for row in csvreader: 
            rows.append(row) 

    # Iterates through each csv row and generates c code
    for row in rows:
        # The piece of code to copy & paste
        if (alt):
            code_str = 'case ' + row[0].rstrip() + ": unimplementedInstruction(state); break;"
        
        else:
            code_str = 'case '
            code_str += row[0].rstrip() + ': printf(\"'
            
            if (row[1] != '-'):
                code_str += row[1]

                if (row[2] is ''):
                    code_str += '\\n\"); break;'
                
                else:
                    while (len(code_str) is not 26):
                        code_str += ' '
                    
                    reg = row[2]
                    for char in reg:
                        if (char is ','):
                            break
                        
                        else:
                            code_str += char

                    # Case for 1 byte instuction
                    if (row[3] is '1'):
                        code_str += '\\n\"); break;'
                    
                    # Case for 2 byte instruction
                    elif(row[3] is '2'):
                        code_str += ',#$%02x\\n\", code[1]); opbytes=2; break;'
                    
                    # Case for 3 byte instruction
                    elif(row[3] is '3'):
                        code_str += ',#$%02x%02x\\n", code[2], code[1]); opbytes=3; break;'
            
            else:
                code_str += 'NOP\\n\"); break;'
        
        print(code_str)

if __name__ == '__main__':
    csv_to_code('opcodes.csv', True)