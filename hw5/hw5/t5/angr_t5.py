import angr
def main():
        project= angr.Project("./angr1")
        print("finding the easter egg...")
        sm = project.factory.simulation_manager(project.factory.entry_state())
        sm.explore(find=0x4007b1)
        found = sm.found[0]
        solution1 = found.posix.dumps(0)
        print("easter egg found!")
        print("solu1",repr(solution1))
        with open('input1_t5', 'wb') as fp:
             fp.write(solution1)
        stdout1 = found.posix.dumps(1)

        print(repr(stdout1))
        return solution1,stdout1

if __name__ == '__main__':

        print(repr(main()))
