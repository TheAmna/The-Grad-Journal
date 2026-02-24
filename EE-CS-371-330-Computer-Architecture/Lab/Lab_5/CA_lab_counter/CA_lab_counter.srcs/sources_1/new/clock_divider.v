//Divides the 100 MHz Basys3 system clock down
//  to a slow enable-pulse used by the FSM counter.

module clock_divider #(
    parameter MAX_COUNT = 25_000_000
)(
    input  wire clk,
    input  wire rst,
    output reg  slow_clk
);

    reg [$clog2(MAX_COUNT)-1 : 0] count;

    always @(posedge clk) begin
        if (rst) begin
            count    <= 0;
            slow_clk <= 1'b0;
        end else begin
            slow_clk <= 1'b0;
            if (count == MAX_COUNT - 1) begin
                count    <= 0;
                slow_clk <= 1'b1;
            end else begin
                count <= count + 1;
            end
        end
    end

endmodule