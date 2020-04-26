from angr import Project, SimProcedure
project= Project("./angr2")
def main():

        #project= Project("./angr2")
        print("finding the easter egg...")
        project.hook_symbol('mm', mm())      
        sm = project.factory.simulation_manager(project.factory.entry_state())

        sm.explore(find=0x400898)
        
        found = sm.found[0]

        solution1 = found.posix.dumps(0)
        print("easter egg found!")

        print(repr(solution1))

        with open('input1_t6', 'wb') as fp:

            fp.write(solution1)


        stdout1 = found.posix.dumps(1)

        print(repr(stdout1))
        return solution1,stdout1

class mm(SimProcedure):
    def run(self,input_): 
        return input_ + 0x4

if __name__ == '__main__':
    print(repr(main()))
    
