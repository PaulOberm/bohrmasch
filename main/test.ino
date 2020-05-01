// Unit test for revolution calculation
test(spindleInstance) {
  assertEqual(spindleInstance.calculateRevolutionsPerMinute(1), (unsigned int) 30);
  assertEqual(spindleInstance.calculateRevolutionsPerMinute(2), (unsigned int) 60);
  assertEqual(spindleInstance.calculateRevolutionsPerMinute(3), (unsigned int) 90);
  assertEqual(spindleInstance.calculateRevolutionsPerMinute(10), (unsigned int) 300);
}
