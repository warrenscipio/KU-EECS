VERSION 6
BEGIN SCHEMATIC
    BEGIN ATTR DeviceFamilyName "spartan3e"
        DELETE all:0
        EDITNAME all:0
        EDITTRAIT all:0
    END ATTR
    BEGIN NETLIST
        SIGNAL A
        SIGNAL B
        SIGNAL C
        SIGNAL XLXN_7
        SIGNAL XLXN_8
        SIGNAL XLXN_10
        SIGNAL XLXN_12
        SIGNAL XLXN_13
        SIGNAL XLXN_14
        SIGNAL Y
        PORT Input A
        PORT Input B
        PORT Input C
        PORT Output Y
        BEGIN BLOCKDEF inv
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -32 64 -32 
            LINE N 224 -32 160 -32 
            LINE N 64 -64 128 -32 
            LINE N 128 -32 64 0 
            LINE N 64 0 64 -64 
            CIRCLE N 128 -48 160 -16 
        END BLOCKDEF
        BEGIN BLOCKDEF and2
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 64 -64 
            LINE N 0 -128 64 -128 
            LINE N 256 -96 192 -96 
            ARC N 96 -144 192 -48 144 -48 144 -144 
            LINE N 144 -48 64 -48 
            LINE N 64 -144 144 -144 
            LINE N 64 -48 64 -144 
        END BLOCKDEF
        BEGIN BLOCKDEF or3
            TIMESTAMP 2000 1 1 10 10 10
            LINE N 0 -64 48 -64 
            LINE N 0 -128 72 -128 
            LINE N 0 -192 48 -192 
            LINE N 256 -128 192 -128 
            ARC N 28 -256 204 -80 112 -80 192 -128 
            ARC N -40 -184 72 -72 48 -80 48 -176 
            LINE N 48 -64 48 -80 
            LINE N 48 -192 48 -176 
            LINE N 112 -80 48 -80 
            ARC N 28 -176 204 0 192 -128 112 -176 
            LINE N 112 -176 48 -176 
        END BLOCKDEF
        BEGIN BLOCK XLXI_1 inv
            PIN I A
            PIN O XLXN_7
        END BLOCK
        BEGIN BLOCK XLXI_2 inv
            PIN I B
            PIN O XLXN_8
        END BLOCK
        BEGIN BLOCK XLXI_3 inv
            PIN I C
            PIN O XLXN_10
        END BLOCK
        BEGIN BLOCK XLXI_5 and2
            PIN I0 XLXN_8
            PIN I1 XLXN_7
            PIN O XLXN_14
        END BLOCK
        BEGIN BLOCK XLXI_6 and2
            PIN I0 XLXN_10
            PIN I1 B
            PIN O XLXN_13
        END BLOCK
        BEGIN BLOCK XLXI_7 and2
            PIN I0 XLXN_8
            PIN I1 C
            PIN O XLXN_12
        END BLOCK
        BEGIN BLOCK XLXI_8 or3
            PIN I0 XLXN_12
            PIN I1 XLXN_13
            PIN I2 XLXN_14
            PIN O Y
        END BLOCK
    END NETLIST
    BEGIN SHEET 1 3520 2720
        BEGIN BRANCH A
            WIRE 528 816 720 816
            WIRE 720 816 800 816
        END BRANCH
        BEGIN BRANCH B
            WIRE 512 992 720 992
            WIRE 720 992 752 992
            WIRE 752 992 1312 992
            WIRE 1312 992 1536 992
            WIRE 752 992 752 1040
            WIRE 752 1040 864 1040
        END BRANCH
        BEGIN BRANCH C
            WIRE 512 1152 736 1152
            WIRE 736 1152 864 1152
            WIRE 864 1152 1296 1152
            WIRE 1296 1152 1408 1152
            WIRE 1408 1152 1408 1200
            WIRE 1408 1200 1536 1200
            WIRE 784 1088 864 1088
            WIRE 864 1088 864 1152
            WIRE 784 1088 784 1200
            WIRE 784 1200 864 1200
        END BRANCH
        IOMARKER 528 816 A R180 28
        IOMARKER 512 992 B R180 28
        IOMARKER 512 1152 C R180 28
        INSTANCE XLXI_1 800 848 R0
        INSTANCE XLXI_2 864 1072 R0
        INSTANCE XLXI_3 864 1232 R0
        INSTANCE XLXI_5 1536 912 R0
        INSTANCE XLXI_6 1536 1120 R0
        INSTANCE XLXI_7 1536 1328 R0
        INSTANCE XLXI_8 2000 1152 R0
        BEGIN BRANCH XLXN_7
            WIRE 1024 816 1280 816
            WIRE 1280 784 1280 816
            WIRE 1280 784 1536 784
        END BRANCH
        BEGIN BRANCH XLXN_8
            WIRE 1088 1040 1328 1040
            WIRE 1328 1040 1328 1264
            WIRE 1328 1264 1536 1264
            WIRE 1328 848 1328 1040
            WIRE 1328 848 1536 848
        END BRANCH
        BEGIN BRANCH XLXN_10
            WIRE 1088 1200 1312 1200
            WIRE 1312 1056 1312 1200
            WIRE 1312 1056 1536 1056
        END BRANCH
        BEGIN BRANCH XLXN_12
            WIRE 1792 1232 2000 1232
            WIRE 2000 1088 2000 1232
        END BRANCH
        BEGIN BRANCH XLXN_13
            WIRE 1792 1024 2000 1024
        END BRANCH
        BEGIN BRANCH XLXN_14
            WIRE 1792 816 2000 816
            WIRE 2000 816 2000 960
        END BRANCH
        BEGIN BRANCH Y
            WIRE 2256 1024 2336 1024
        END BRANCH
        IOMARKER 2336 1024 Y R0 28
    END SHEET
END SCHEMATIC
