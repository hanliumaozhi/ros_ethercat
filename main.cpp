#include <unistd.h>
#include "signal.h"

#include "EcatAdmin.h"

static int run = 1;

void signal_handler(int sig)
{
    run = 0;
}

int main(void) {

    //加6个电机
    //使用EcatAdmin::add_motor()
    EcatAdmin::add_motor(1, "joint_1", 1, 0, 0x000002E1, 0x00000000);
    EcatAdmin::add_motor(2, "joint_2", 2, 0, 0x000002E1, 0x00000000);
    EcatAdmin::add_motor(3, "joint_3", 3, 0, 0x000002E1, 0x00000000);
    EcatAdmin::add_motor(4, "joint_4", 4, 0, 0x000002E1, 0x00000000);
    EcatAdmin::add_motor(5, "joint_5", 5, 0, 0x000002E1, 0x00000000);
    EcatAdmin::add_motor(6, "joint_6", 6, 0, 0x000002E1, 0x00000000);


    EcatAdmin::start_for_ros_control();

    int cycle_counter = 0;

    while(run)
    {
        ecrt_master_receive(EcatAdmin::master);
        ecrt_domain_process(EcatAdmin::domain1);

        EcatAdmin::check_domain_state();

        if (!(cycle_counter % 100)) {
            EcatAdmin::check_master_state();
        }

        ecrt_domain_queue(EcatAdmin::domain1);
        ecrt_master_send(EcatAdmin::master);

        usleep(10000);
    }

    EcatAdmin::shutdown();
    return 0;
}