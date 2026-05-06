from migen import *
from litex.soc.interconnect.csr import *

class AdjustableBlink(Module, AutoCSR):
    def __init__(self, led_pin):
        # CSRStorage (CPU -> Hardware)
        # Default value: 25,000,000 (0.5s at 50MHz)
        self.period = CSRStorage(32, reset=25000000, description="Blink period in clock cycles")
        
        # Internal Logic
        counter = Signal(32)
        
        self.sync += [
            If(counter >= self.period.storage,
                counter.eq(0),
                led_pin.eq(~led_pin) # Toggle the LED
            ).Else(
                counter.eq(counter + 1)
            )
        ]