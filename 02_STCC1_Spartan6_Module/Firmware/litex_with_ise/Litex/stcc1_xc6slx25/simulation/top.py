from migen import *
from encoder1 import BT656SyncGen

def bt656_tb(dut):
    # Run for a few lines of video
    for i in range(50000):
        # You can observe signals here if needed
        yield

if __name__ == "__main__":
    dut = BT656SyncGen()

    run_simulation(
        dut,
        bt656_tb(dut),
        vcd_name="bt656.vcd",   # <<< THIS generates the VCD
        clocks={"sys": 27e6}    # Typical PAL pixel clock (optional but recommended)
    )
