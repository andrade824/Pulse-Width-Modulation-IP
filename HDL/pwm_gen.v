`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Engineer: Devon Andrade
// 
// Create Date: 05/18/2014 02:43:10 PM
// Design Name: PWM Generator
// Module Name: pwm_gen
// Project Name: PWM Generator
// Target Devices: xc7z010clg400-1
// Tool Versions: Vivado 2014.1
// 
// Parameters:
//      WIDTH - How many bits the counter, load, and compare values are
//
// Inputs:
//      load - The value at which the counter will reset to zero and set the output
//      compare - The value at which the counter will clear the output
//      control - Register bit map:
//              Bit 0: PWM Enable - Output is enabled if this bit is high, disabled otherwise
//
// Outputs:
//      pwm_out - The pulse width modulated signal, or ground if disabled
//////////////////////////////////////////////////////////////////////////////////


module pwm_gen
#(parameter WIDTH=32) (
    input wire clk, rst,
    input wire [WIDTH-1:0] load, compare, control,
    output wire pwm_out
);
    
    reg [WIDTH-1:0] count;
    reg pwm_out_r;
    
    // Make sure output is low if PWM is disabled
    assign pwm_out = control[0] & pwm_out_r;
    
    initial begin
        pwm_out_r = 1'b0;
        count = {WIDTH{1'b0}};
    end
    
    // The counter
    always @(posedge clk) begin
        if(!rst)
            count = {WIDTH{1'b0}};
        else if (count < load && control[0])
            count = count + 1;
        else
            count = 0;
    end
    
    always @(negedge clk) begin
        if(!rst)
            pwm_out_r = 1'b0;
        else begin
            case(count)
                0 : pwm_out_r = 1'b1;
                compare : pwm_out_r = 1'b0;
                default : pwm_out_r = pwm_out_r;
            endcase
        end
    end

endmodule
