//
// Created by han on 16-12-26.
//

#include "motor.h"

Motor::Motor(int joint_no, std::string joint_name, uint16_t alias, uint16_t position, uint32_t vendor_id, uint32_t product_code):
                joint_no_(joint_no),
                joint_name_(joint_name),
                alias_(alias),
                position_(position),
                vendor_id_(vendor_id),
                product_code_(product_code){

                    for(int i = 0; i != 6; ++i){
                        index_to_offset_list_.push_back(current_index_++);
                    }

                    pdo_index_ = {0x6040, 0x607A, 0x6081, 0x6041, 0x6064, 0x606C};
                    pdo_subindex_ = {0, 0, 0, 0, 0, 0};

            }


uint16_t Motor::get_alias() const noexcept{
    return alias_;
}

uint16_t Motor::get_position() const noexcept{
    return position_;
}

uint32_t Motor::get_vendor_id() const noexcept{
    return vendor_id_;
}

uint32_t Motor::get_product_code() const noexcept{
    return product_code_;
}

int Motor::current_index_ = 0;

unsigned int Motor::regs[ECAT_REG_TABLE_SIZE] = {0};

int Motor::get_control_word() const noexcept{
    return index_to_offset_list_[0];
}

int Motor::get_r_position() const noexcept{
    return index_to_offset_list_[1];
}

int Motor::get_r_velocity() const noexcept{
    return index_to_offset_list_[2];
}


int Motor::get_status_word() const noexcept{
    return index_to_offset_list_[3];
}

int Motor::get_t_position() const noexcept{
    return index_to_offset_list_[4];
}

int Motor::get_t_velocity() const noexcept{
    return index_to_offset_list_[5];
}