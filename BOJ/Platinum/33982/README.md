- Approach: implementaion, data structures, sorting, binary search, simulation, set/map, priority_queue
- Space Complexity: O(n + m + Σk)
- Time Complexity: O((m + Σk)\*log(n) + Σk*log(Σk)
- Mistakes:
> When a duplicate visit coincides with a missing edge, the output was incorrectly displaying "No: Edge Absence" instead of the required "No: Duplicate Visit"
> Output "Duplicate Visit" instead of "Edge Absence" if both errors occur simultaneously
> If a duplicate visit occurred where no outgoing edge existed, the train was treated as having departed. Now, the station is correctly marked as blocked/stuck in this scenario
