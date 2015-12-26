----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:24:43 03/14/2013 
-- Design Name: 
-- Module Name:    threebitxor - Behavioral 
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

entity threebitxor is
    PORT (
		A,B,C : IN STD_LOGIC;
		H : OUT STD_LOGIC);
end threebitxor;

architecture Structural of threebitxor is
-- Component Declaration
 COMPONENT twobitxor IS
 PORT (
 A,B : IN STD_LOGIC;
 G : OUT STD_LOGIC);
 END COMPONENT twobitxor;
 
 -- Signal Declaration
 SIGNAL AxorB: STD_LOGIC;

begin

-- Component Instantiation
 AB: twobitxor
 PORT MAP (
A => A,
B => B,
G => AxorB);
ABC: twobitxor
 PORT MAP (
A => AxorB,
B => C,
G => H);
END ARCHITECTURE Structural;



