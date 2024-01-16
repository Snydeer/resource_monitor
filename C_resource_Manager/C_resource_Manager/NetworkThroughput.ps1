#Get-Bandwidth.ps1
# Measure the Network interface IO over a period of half a minute (0.5)

$startTime = get-date
$endTime = $startTime.addMinutes(0.5)
$timeSpan = new-timespan $startTime $endTime

$count = 0
$totalBandwidth = 0


   # Get an object for the network interfaces, excluding any that are currently disabled.
   $colInterfaces = Get-CimInstance -class Win32_PerfFormattedData_Tcpip_NetworkInterface |select BytesTotalPersec, CurrentBandwidth,PacketsPersec|where {$_.PacketsPersec -gt 0}

   foreach ($interface in $colInterfaces) {
      $bitsPerSec = $interface.BytesTotalPersec * 8
      $totalBits = $interface.CurrentBandwidth

      # Exclude Nulls (any WMI failures)
      if ($totalBits -gt 0) {
         $result = (($bitsPerSec) / 1024)
         Write-Host "$result `n"
		 
         # Overwrite the net.dat file with the new $result value
		 $result | Out-File -FilePath "net.dat" -Force
         $count++
      }
   }
   #Start-Sleep -milliseconds 100

   # recalculte the remaining time
   #$timeSpan = new-timespan $(Get-Date) $endTime


