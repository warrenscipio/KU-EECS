----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:27:07 04/18/2013 
-- Design Name: 
-- Module Name:    fourbitcounter - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fourbitcounter is
PORT(
		message_clk : IN STD_LOGIC;
		enable : IN STD_LOGIC;
		load_n : IN STD_LOGIC;
		initial_value : IN STD_LOGIC_VECTOR(3 downto 0);
		clear_n : IN STD_LOGIC;
		counter_out : OUT STD_LOGIC_VECTOR(3 downto 0));


end fourbitcounter;

architecture Behavioral of fourbitcounter is

signal counter_signal:std_logic_vector(3 downto 0) :="0000";

begin



process (message_clk, clear_n)

begin
   if clear_n='0' then
     counter_signal <= (others=>'0');
   elsif (message_clk'event and message_clk='1') then
     if load_n = '0' then
     counter_signal <=initial_value;
     else
     if enable ='1' then
     counter_signal <= counter_signal +1;
     else
     counter_signal <= counter_signal;
     end if;
   end if;
   end if;
	
end process;

counter_out <= counter_signal;

end Behavioral;