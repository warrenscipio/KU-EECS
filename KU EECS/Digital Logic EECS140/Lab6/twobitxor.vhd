----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:25:17 03/14/2013 
-- Design Name: 
-- Module Name:    twobitxor - Behavioral 
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

entity twobitxor is
    Port ( 
		A,B : IN STD_LOGIC;
		G : OUT STD_LOGIC);
end twobitxor;

architecture Behavioral of twobitxor is

begin

G <= (A AND (NOT B)) OR ((NOT A) AND B);

end Behavioral;

