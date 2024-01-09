$currentPath = Get-Location;
Write-Output "Current Path: $currentPath"

$confirmation = Read-Host "Do you want to delete all .exe files in this directory and its subdirectories? (Y/N)"

if ($confirmation -eq "Y" -or $confirmation -eq "y") {
    Get-ChildItem -Path $currentPath -Recurse -Include *.exe | ForEach-Object {
        Write-Output "Deleting: $($_.FullName)"
        Remove-Item $_.FullName -Force
    }
    Write-Output "Operation completed. .exe files deleted."
} else {
    Write-Output "Operation canceled."
}
