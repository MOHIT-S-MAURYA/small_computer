#include <iostream>
#include <fstream>

using namespace std;

const int memSize = 1000;
const int registers = 6;

class SMAC
{
public:
    // initialisation of CPU
    // register 0 is not given to user, register 1 is accumulator, 2-5 are general purpose registers
    // memory 0 holds -1
    SMAC() : accumulator(0), pc(0), count(0)
    {
        fill_n(memory, memSize, 0);
        memory[0] = -1;
        fill_n(reg, registers, 0);
        reg[0] = -1;
        fill_n(program_memory, 100, 0);
    }

    // load file into program memory
    bool load(string filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "unable to open file " << endl;
            return false;
        }
        string line;
        while (getline(file, line) && count < 100)
        {
            program_memory[count++] = stoi(line);
        }
        file.close();
        return true;
    }




    // MOVE OPERATIONS
    // move to register  - 09
    void move_to_registers(int registers, int location)
    {   
        reg[registers] = memory[location];
        if (registers == 01)
        {
            accumulator = memory[location];
        }
        pc++;
    }

    // move to location - 10
    void move_to_location(int registers, int location)
    {   memory[location] = reg[registers];
        if (registers == 01)
        {
            memory[location] = accumulator;
        }
        pc++;
    }




    // INPUT AND OUTPUT
    // user input-81
    void input(int registers, int location)
    {
        cout << "enter the value : ";
        
        // if location in zero
        if (location == 0 && registers != 0)
        {
            cin >> reg[registers];
            if (registers == 01)
            {
                accumulator = reg[registers];
            }
        }

        // if registers is zero
        if (registers == 0 && location != 0)
        {
            cin >> memory[location];
        }

        // if both location and registers is non zero
        if (location != 0 && registers != 0)
        {
            cin >> reg[registers];
            memory[location] = reg[registers];

            if (registers == 1)
            {
                accumulator = reg[registers];
            }
        }
        pc++;
    }

    // output-82
    void output(int registers, int location)
    {
        cout <<endl;

            if (registers == 01)
            {
                memory[location] = accumulator;
                cout << accumulator << endl;
            }
            else
            {
                memory[location] = reg[registers];
                cout << reg[registers] << endl;
            }
        pc++;
    }




    // ARITHMATIC OPERATIONS
    // addition of numbers-11
    void add(int registers, int location)
    {   
        if(registers!=0 && location==0){
            accumulator =accumulator+ reg[registers];
            // cout<<accumulator<<"----"<<memory[location]<<endl;
        }else if(registers==0 && location !=0){
            accumulator +=accumulator+ memory[location];
        }else{
            if (registers == 01)
            {
                accumulator = accumulator + memory[location];
            }
            reg[registers]= reg[registers] + memory[location];
        }
        pc++;
    }

    // subtraction of numbers-12
    void sub(int registers, int location)
    {
        if(registers!=0 && location==0){
            accumulator -= reg[registers];
        }else if(registers==0 && location !=0){
            accumulator -= memory[location];
        }else{
            if (registers == 01)
            {
                accumulator -= memory[location];
            }
            reg[registers] -=memory[location];
        }
        pc++;
    }

    // multiply numbers-13
    void multiply(int registers, int location)
    {
        if(registers!=0 && location==0){
            if(registers==1){
                accumulator=accumulator*memory[location];
            }else
            {accumulator *= reg[registers];}
        }else if(registers==0 && location !=0){
            accumulator *= memory[location];
        }else if (registers!=0 && location!=0){
            reg[registers] *=memory[location];
            if (registers == 01)
            {
                accumulator *= memory[location];
                reg[registers] =accumulator;
            }
        }
        pc++;
    }

    // divide numbers-14
    void divide(int registers, int location)
    {
        if(registers!=0 && location==0){
            if(registers==1){
                accumulator=accumulator/memory[location];
            }else
            {accumulator /= reg[registers];}
        }else if(registers==0 && location !=0){
            accumulator /= memory[location];
        }else if (registers!=0 && location!=0){
            reg[registers] /=memory[location];
            if (registers == 01)
            {
                accumulator /= memory[location];
                reg[registers] =accumulator;
            }
        }
        pc++;
    }





    // INCREMENT AND DECREMENT
    // increment -23
    void increment(int registers, int location)
    {   
        if(registers!=0 && location==0){
            reg[registers]++;
            if(registers==1){
                accumulator++;
            }
        }else if(registers==0 && location !=0){
            memory[location]++;
        }else{
            reg[registers]=location++;
        }
        pc++;
    }

    // decrement accumulator-24
    void decrement(int registers, int location)
    {
        if(registers!=0 && location==0){
            reg[registers]--;
            if(registers==1){
                accumulator--;
            }
        }else if(registers==0 && location !=0){
            memory[location]--;
        }else{
            reg[registers]=location--;
        }
        pc++;
    }





    // JUMP STATEMENTS
    // jump-30
    void jump(int location)
    {
        pc = location;
        pc++;
    }

    // jump if nagative-31
    void jump_if_negative(int registers, int location)
    {
            if (registers == 01)
            {
                if (accumulator < 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
            else
            {
                if (reg[registers] < 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
    }

    // jump if positive-32
    void jump_if_positive(int registers, int location)
    {
        if (registers == 01)
            {
                if (accumulator > 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
            else
            {
                if (reg[registers] > 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
    }

    // jump if not zero-33
    void jump_if_not_zero(int registers, int location)
    {
        if (registers == 01)
            {
                if (accumulator != 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
            else
            {
                if (reg[registers] != 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
    }

    // jump if zero-34
    void jump_if_zero(int registers, int location)
    {
        if (registers == 01)
            {
                if (accumulator == 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
            else
            {
                if (reg[registers] == 0)
                {
                    pc = location;
                }
                else
                {
                    pc++;
                }
            }
    }




    // EXECUTE PROGRAM 
    void execute()
    {
        pc = 0;
        while (pc < memSize)
        {
            if (pc < 0 || pc > memSize)
            {
                cout << "invalid memory location" << endl;
                break;
            }
            int instruction = program_memory[pc];
            int opcode = instruction / 1000000;
            int registers = (instruction / 10000) % 100;
            int location = instruction % 10000;
            
            // VALIDATION CHECK

            if (registers < 0 || registers > 5)
            {
                cout << "invalid register" << endl;
                break;
            }
            if (location < 0 || location > memSize)
            {
                cout << "invalid memory location" << endl;
                break;
            }


            // method(opcode) calls 

            switch (opcode)
            {
            case 9:
                move_to_registers(registers, location);
                break;
            case 10:
                move_to_location(registers, location);
                break;
            case 81:
                input(registers,location);
                break;
            case 82:
                output(registers, location);
                break;

            case 11:
                add(registers, location);
                break;

            case 12:
                sub(registers, location);
                break;

            case 13:
                multiply(registers, location);
                break;

            case 14:
                divide(registers, location);
                break;

            case 23:
                increment(registers, location);
                break;

            case 24:
                decrement(registers, location);
                break;

            case 30:
                jump(location);
                break;

            case 31:
                jump_if_negative(registers, location);
                break;

            case 32:
                jump_if_positive(registers, location);
                break;

            case 33:
                jump_if_not_zero(registers, location);
                break;

            case 34:
                jump_if_zero(registers, location);
                break;

            case 90:
                cout << "Thank you for using.Visit again.." << endl;
                return;

            default:
                cerr << "error: Unknown Opcode:" << opcode;
                return;
            }
        }
    }

private:
    double memory[memSize], reg[registers], accumulator;
    int pc, count, program_memory[100];
};

int main()
{
    SMAC cpu;
    string filename;
    while (true)
    {
        cout << "enter the file name : ";
        cin >> filename;
        if (cpu.load(filename))
        {
            cpu.execute();
            break;
        }
    }
    return 0;
}
