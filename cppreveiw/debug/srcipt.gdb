# Set signal handlers
handle SIGABRT stop

set pagination off

# Set counter variable
set $i = 0

# Repeat execution until SIGABRT is received or counter reaches a certain value
while ($i < 2000)
  run
  print("iterator")
  print($i)
  # Check for SIGABRT signal
  if $_siginfo
    if  $_siginfo.si_signo == 6
        # SIGABRT received, stop execution
        bt
        #quit
        loopbreak
    end
  end
  
  # Increment counter
  set $i = $i + 1
end